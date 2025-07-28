from collections import defaultdict
from typing import List, Dict, Set, Tuple, Optional
import copy

class Edge:
    """Lớp biểu diễn cạnh trong đồ thị tổng quát"""
    
    def __init__(self, to: int, is_directed: bool, edge_id: int):
        self.to = to
        self.is_directed = is_directed
        self.id = edge_id

class EdgeInfo:
    """Thông tin chi tiết về cạnh"""
    
    def __init__(self, from_vertex: int, to_vertex: int, edge_id: int, 
                 is_directed: bool, edge_type: str, is_self_loop: bool):
        self.from_vertex = from_vertex
        self.to_vertex = to_vertex
        self.id = edge_id
        self.is_directed = is_directed
        self.type = edge_type
        self.is_self_loop = is_self_loop

class GeneralGraphDFS:
    """DFS cho đồ thị tổng quát"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]
        self.edge_map = defaultdict(list)
        self.self_loop_count = [0] * num_vertices
        self.edge_id_counter = 0
        self.reset_arrays()
    
    def reset_arrays(self):
        self.visited = [False] * self.num_vertices
        self.start_time = [0] * self.num_vertices
        self.finish_time = [0] * self.num_vertices
        self.parent = [-1] * self.num_vertices
        self.dfs_order = []
        self.edge_info_list = []
        self.time_counter = 0
    
    def add_edge(self, u: int, v: int, is_directed: bool = False):
        """Thêm cạnh vào đồ thị tổng quát"""
        edge = Edge(v, is_directed, self.edge_id_counter)
        self.edge_id_counter += 1
        self.adj_list[u].append(edge)
        
        # Xử lý khuyên
        if u == v:
            self.self_loop_count[u] += 1
            print(f"Thêm khuyên tại đỉnh {u} (ID: {edge.id})")
        else:
            # Cạnh thường - thêm vào cả 2 chiều nếu vô hướng
            if not is_directed:
                reverse_edge = Edge(u, False, self.edge_id_counter)
                self.edge_id_counter += 1
                self.adj_list[v].append(reverse_edge)
            
            direction_str = "có hướng" if is_directed else "vô hướng"
            print(f"Thêm cạnh {u} -> {v} ({direction_str}) (ID: {edge.id})")
        
        # Cập nhật bản đồ cạnh
        edge_key = (u, v)
        self.edge_map[edge_key].append(edge)
    
    def dfs_recursive(self, u: int):
        """DFS đệ quy cho đồ thị tổng quát"""
        self.visited[u] = True
        self.time_counter += 1
        self.start_time[u] = self.time_counter
        self.dfs_order.append(u)
        
        print(f"Thăm đỉnh {u} (start: {self.start_time[u]})")
        
        # Xử lý khuyên trước
        if self.self_loop_count[u] > 0:
            print(f"  Phát hiện {self.self_loop_count[u]} khuyên tại đỉnh {u}")
            self.edge_info_list.append(
                EdgeInfo(u, u, -1, True, "SELF_LOOP", True)
            )
        
        # Duyệt các cạnh thường
        for edge in self.adj_list[u]:
            v = edge.to
            is_directed = edge.is_directed
            
            # Bỏ qua khuyên (đã xử lý ở trên)
            if u == v:
                continue
            
            if not self.visited[v]:
                self.parent[v] = u
                self.edge_info_list.append(
                    EdgeInfo(u, v, edge.id, is_directed, "TREE", False)
                )
                direction_str = "có hướng" if is_directed else "vô hướng"
                print(f"  Cạnh cây: {u} -> {v} ({direction_str})")
                self.dfs_recursive(v)
            else:
                # Phân loại cạnh phức tạp
                edge_type = self._classify_edge(u, v, is_directed)
                self.edge_info_list.append(
                    EdgeInfo(u, v, edge.id, is_directed, edge_type, False)
                )
                
                direction_str = "có hướng" if is_directed else "vô hướng"
                print(f"  Cạnh {edge_type}: {u} -> {v} ({direction_str})", end="")
                
                if edge_type == "BACK":
                    print(" (chu trình!)", end="")
                print()
        
        self.time_counter += 1
        self.finish_time[u] = self.time_counter
        print(f"Kết thúc đỉnh {u} (finish: {self.finish_time[u]})")
    
    def _classify_edge(self, u: int, v: int, is_directed: bool) -> str:
        """Phân loại cạnh dựa trên thời gian và hướng"""
        if (self.start_time[v] < self.start_time[u] and 
            self.finish_time[v] == 0):
            return "BACK"  # Cạnh ngược - tạo chu trình
        
        if self.start_time[v] > self.start_time[u]:
            return "FORWARD"  # Cạnh xuôi
        
        if self.finish_time[v] < self.start_time[u]:
            return "CROSS"  # Cạnh chéo
        
        # Trường hợp đặc biệt cho cạnh vô hướng
        if not is_directed and self.parent[u] == v:
            return "PARENT"  # Cạnh về cha (không tính chu trình)
        
        return "UNKNOWN"
    
    def dfs_complete(self):
        """DFS toàn bộ đồ thị tổng quát"""
        self.reset_arrays()
        
        print("DFS toàn bộ đồ thị tổng quát:")
        component_count = 0
        
        for i in range(self.num_vertices):
            if not self.visited[i]:
                component_count += 1
                print(f"\nThành phần liên thông {component_count}:")
                self.dfs_recursive(i)
        
        print(f"\nTổng số thành phần liên thông: {component_count}")
        self.analyze_complex_graph()
    
    def analyze_complex_graph(self):
        """Phân tích đồ thị tổng quát"""
        print("\nPhân tích đồ thị tổng quát:")
        
        tree_edges = back_edges = forward_edges = cross_edges = 0
        self_loops = directed_edges = undirected_edges = 0
        has_cycle = False
        
        for info in self.edge_info_list:
            if info.is_self_loop:
                self_loops += 1
                continue
            
            if info.is_directed:
                directed_edges += 1
            else:
                undirected_edges += 1
            
            if info.type == "TREE":
                tree_edges += 1
            elif info.type == "BACK":
                back_edges += 1
                has_cycle = True
            elif info.type == "FORWARD":
                forward_edges += 1
            elif info.type == "CROSS":
                cross_edges += 1
        
        print("Thống kê cạnh:")
        print(f"- Cạnh cây: {tree_edges}")
        print(f"- Cạnh ngược: {back_edges}")
        print(f"- Cạnh xuôi: {forward_edges}")
        print(f"- Cạnh chéo: {cross_edges}")
        print(f"- Khuyên: {self_loops}")
        print(f"- Cạnh có hướng: {directed_edges}")
        print(f"- Cạnh vô hướng: {undirected_edges}")
        
        print(f"\nĐồ thị có chu trình: {'Có' if has_cycle else 'Không'}")
        
        # Phân tích tính chất đặc biệt
        self.analyze_special_properties()
    
    def analyze_special_properties(self):
        """Phân tích tính chất đặc biệt"""
        print("\nPhân tích tính chất đặc biệt:")
        
        # Kiểm tra đồ thị Euler
        is_eulerian = self.check_eulerian()
        print(f"Đồ thị Euler: {'Có' if is_eulerian else 'Không'}")
        
        # Kiểm tra tính liên thông mạnh (cho phần có hướng)
        is_strongly_connected = self.check_strong_connectivity()
        print(f"Liên thông mạnh: {'Có' if is_strongly_connected else 'Không'}")
        
        # Đếm số bậc của mỗi đỉnh
        self.print_degree_information()
    
    def check_eulerian(self) -> bool:
        """Kiểm tra tính Euler đơn giản"""
        for i in range(self.num_vertices):
            degree = len(self.adj_list[i]) + self.self_loop_count[i]
            if degree % 2 != 0:
                return False
        return True
    
    def check_strong_connectivity(self) -> bool:
        """Kiểm tra tính liên thông mạnh đơn giản"""
        self.reset_arrays()
        self.dfs_recursive(0)
        
        for i in range(self.num_vertices):
            if not self.visited[i]:
                return False
        return True
    
    def print_degree_information(self):
        """In thông tin bậc đỉnh"""
        print("\nThông tin bậc đỉnh:")
        print("Đỉnh\tBậc vào\tBậc ra\tKhuyên")
        print("----\t-------\t------\t------")
        
        for i in range(self.num_vertices):
            in_degree = out_degree = 0
            
            # Tính bậc ra
            out_degree = len(self.adj_list[i])
            
            # Tính bậc vào
            for j in range(self.num_vertices):
                for edge in self.adj_list[j]:
                    if edge.to == i and j != i:
                        in_degree += 1
            
            print(f"{i}\t{in_degree}\t{out_degree}\t{self.self_loop_count[i]}")
    
    def print_general_graph(self):
        """In biểu diễn đồ thị tổng quát"""
        print("Biểu diễn đồ thị tổng quát:")
        
        for i in range(self.num_vertices):
            print(f"Đỉnh {i}:")
            
            if self.self_loop_count[i] > 0:
                print(f"  Khuyên: {self.self_loop_count[i]}")
            
            print("  Kề: ", end="")
            for edge in self.adj_list[i]:
                if edge.to != i:  # Không in khuyên ở đây
                    direction = "(→)" if edge.is_directed else "(↔)"
                    print(f"{edge.to}{direction} ", end="")
            print()
        print()
    
    def find_all_cycles(self):
        """Tìm tất cả chu trình trong đồ thị tổng quát"""
        print("Tìm tất cả chu trình trong đồ thị:")
        
        cycles = []
        current_path = []
        in_path = [False] * self.num_vertices
        
        for i in range(self.num_vertices):
            self._find_cycles_from_vertex(i, current_path, in_path, cycles)
        
        if not cycles:
            print("Không có chu trình")
        else:
            print(f"Tìm thấy {len(cycles)} chu trình:")
            for i, cycle in enumerate(cycles, 1):
                cycle_str = ' -> '.join(map(str, cycle))
                print(f"Chu trình {i}: {cycle_str} -> {cycle[0]}")
    
    def _find_cycles_from_vertex(self, start: int, path: List[int], 
                                in_path: List[bool], cycles: List[List[int]]):
        """Helper function để tìm chu trình từ một đỉnh"""
        path.append(start)
        in_path[start] = True
        
        for edge in self.adj_list[start]:
            next_vertex = edge.to
            
            if next_vertex == start:  # Bỏ qua khuyên
                continue
            
            if in_path[next_vertex]:
                # Tìm thấy chu trình
                try:
                    cycle_start = path.index(next_vertex)
                    cycle = path[cycle_start:]
                    cycles.append(cycle.copy())
                except ValueError:
                    pass
            elif next_vertex not in path:
                self._find_cycles_from_vertex(next_vertex, path, in_path, cycles)
        
        path.pop()
        in_path[start] = False
    
    def dfs_iterative(self, start: int):
        """DFS không đệ quy cho đồ thị tổng quát"""
        self.reset_arrays()
        
        stack = [start]
        print(f"DFS không đệ quy từ đỉnh {start}:")
        
        while stack:
            u = stack.pop()
            
            if not self.visited[u]:
                self.visited[u] = True
                self.time_counter += 1
                self.start_time[u] = self.time_counter
                self.dfs_order.append(u)
                
                print(f"Thăm đỉnh {u} (start: {self.start_time[u]})")
                
                # Xử lý khuyên
                if self.self_loop_count[u] > 0:
                    print(f"  Phát hiện {self.self_loop_count[u]} khuyên tại đỉnh {u}")
                
                # Thêm các đỉnh kề vào stack (thứ tự ngược lại)
                neighbors = []
                for edge in self.adj_list[u]:
                    if edge.to != u and not self.visited[edge.to]:
                        neighbors.append(edge.to)
                
                # Sắp xếp theo thứ tự ngược để có thứ tự duyệt đúng
                neighbors.sort(reverse=True)
                for v in neighbors:
                    stack.append(v)
                    if self.parent[v] == -1:
                        self.parent[v] = u
        print()
    
    def find_bridges_and_cut_vertices(self):
        """Tìm cầu và khớp trong đồ thị"""
        self.reset_arrays()
        
        low = [0] * self.num_vertices  # Giá trị low của mỗi đỉnh
        bridges = []  # Danh sách cầu
        cut_vertices = set()  # Tập hợp các đỉnh khớp
        
        def tarjan_bridge(u: int, parent: int):
            self.visited[u] = True
            self.time_counter += 1
            self.start_time[u] = low[u] = self.time_counter
            children = 0
            
            for edge in self.adj_list[u]:
                v = edge.to
                if u == v:  # Bỏ qua khuyên
                    continue
                
                if not self.visited[v]:
                    children += 1
                    tarjan_bridge(v, u)
                    
                    # Cập nhật low[u]
                    low[u] = min(low[u], low[v])
                    
                    # Kiểm tra cầu
                    if low[v] > self.start_time[u]:
                        bridges.append((u, v))
                    
                    # Kiểm tra đỉnh khớp
                    if (parent == -1 and children > 1) or (parent != -1 and low[v] >= self.start_time[u]):
                        cut_vertices.add(u)
                        
                elif v != parent:
                    low[u] = min(low[u], self.start_time[v])
        
        # Chạy Tarjan cho từng thành phần liên thông
        for i in range(self.num_vertices):
            if not self.visited[i]:
                tarjan_bridge(i, -1)
        
        print("Kết quả tìm cầu và khớp:")
        print(f"Số cầu: {len(bridges)}")
        if bridges:
            print("Danh sách cầu:")
            for bridge in bridges:
                print(f"  ({bridge[0]}, {bridge[1]})")
        
        print(f"Số đỉnh khớp: {len(cut_vertices)}")
        if cut_vertices:
            print("Danh sách đỉnh khớp:", sorted(cut_vertices))
    
    def topological_sort(self):
        """Sắp xếp topo (chỉ có ý nghĩa với đồ thị có hướng không có chu trình)"""
        self.reset_arrays()
        topo_stack = []
        
        def topo_dfs(u: int):
            self.visited[u] = True
            
            for edge in self.adj_list[u]:
                v = edge.to
                if not self.visited[v] and edge.is_directed:  # Chỉ theo cạnh có hướng
                    topo_dfs(v)
            
            topo_stack.append(u)
        
        # Gọi DFS cho tất cả đỉnh
        for i in range(self.num_vertices):
            if not self.visited[i]:
                topo_dfs(i)
        
        result = topo_stack[::-1]
        
        print("Sắp xếp topo (chỉ xét cạnh có hướng):")
        print("Thứ tự:", ' -> '.join(map(str, result)))
        
        return result
    
    def print_times(self):
        """In thông tin thời gian DFS"""
        print("\nThông tin thời gian DFS:")
        print(f"{'Đỉnh':>6} {'Start':>12} {'Finish':>12} {'Cha':>10}")
        print("-" * 40)
        
        for i in range(self.num_vertices):
            print(f"{i:>6} {self.start_time[i]:>12} {self.finish_time[i]:>12} {self.parent[i]:>10}")
        print()
    
    def print_dfs_tree(self):
        """In cây DFS"""
        print("Cây DFS:")
        for i in range(self.num_vertices):
            if self.parent[i] != -1:
                print(f"{self.parent[i]} -> {i}")
        print()

# Demo cho đồ thị tổng quát
def demonstrate_general_graph_dfs():
    print("=== DEMO DFS CHO ĐỒ THỊ TỔNG QUÁT ===\n")
    
    graph = GeneralGraphDFS(6)
    
    # Tạo đồ thị tổng quát phức tạp
    print("Tạo đồ thị tổng quát:")
    
    # Cạnh vô hướng
    graph.add_edge(0, 1, False)
    graph.add_edge(1, 2, False)
    
    # Cạnh có hướng
    graph.add_edge(2, 3, True)
    graph.add_edge(3, 4, True)
    
    # Cạnh bội
    graph.add_edge(0, 1, False)  # Cạnh bội vô hướng
    graph.add_edge(2, 3, True)   # Cạnh bội có hướng
    
    # Khuyên
    graph.add_edge(4, 4, True)   # Khuyên có hướng
    graph.add_edge(5, 5, False)  # Khuyên vô hướng
    
    # Cạnh tạo chu trình
    graph.add_edge(4, 1, True)   # Chu trình có hướng
    graph.add_edge(3, 0, False)  # Chu trình hỗn hợp
    
    print()
    graph.print_general_graph()
    
    # DFS trên đồ thị tổng quát
    print("1. DFS ĐỆ QUY:")
    graph.dfs_complete()
    graph.print_times()
    graph.print_dfs_tree()
    
    # DFS không đệ quy
    print("2. DFS KHÔNG ĐỆ QUY:")
    graph.dfs_iterative(0)
    
    # Tìm chu trình
    print("3. TÌM CHU TRÌNH:")
    graph.find_all_cycles()
    
    # Tìm cầu và khớp
    print("4. TÌM CẦU VÀ KHỚP:")
    graph.find_bridges_and_cut_vertices()
    
    # Sắp xếp topo
    print("5. SẮP XẾP TOPO:")
    graph.topological_sort()

if __name__ == "__main__":
    demonstrate_general_graph_dfs()