"""
Bài 16: Dijkstra trên đồ thị tổng quát
Xử lý mọi loại đồ thị: có hướng/vô hướng, cạnh song song, vòng lặp, không liên thông
"""

import heapq
from typing import List, Tuple, Dict, Optional, Set
from collections import defaultdict
import sys

class GeneralEdge:
    """Cạnh trong đồ thị tổng quát"""
    def __init__(self, from_vertex: int, to_vertex: int, weight: int, 
                 edge_id: int, edge_type: str = "normal"):
        self.from_vertex = from_vertex
        self.to_vertex = to_vertex
        self.weight = weight
        self.id = edge_id
        self.type = edge_type  # "normal", "self-loop", "parallel"

class GraphStatistics:
    """Thống kê đồ thị"""
    def __init__(self):
        self.num_vertices = 0
        self.num_edges = 0
        self.num_self_loops = 0
        self.num_parallel_edges = 0
        self.is_directed = False
        self.is_connected = False
        self.components = []
        self.edge_type_count = defaultdict(int)

class GeneralDijkstra:
    """Dijkstra cho đồ thị tổng quát"""
    
    def __init__(self, num_vertices: int, is_directed: bool = False):
        self.num_vertices = num_vertices
        self.is_directed = is_directed
        self.adj_list = [[] for _ in range(num_vertices)]
        self.edge_id_counter = 0
        self.stats = GraphStatistics()
        self.edge_key_count = defaultdict(int)
        
        self.stats.num_vertices = num_vertices
        self.stats.is_directed = is_directed
        self.reset()
    
    def reset(self):
        """Reset trạng thái cho lần chạy mới"""
        self.dist = [float('inf')] * self.num_vertices
        self.parent = [-1] * self.num_vertices
        self.parent_edge_id = [-1] * self.num_vertices
        self.visited = [False] * self.num_vertices
        self.in_current_component = [False] * self.num_vertices
    
    def add_edge(self, u: int, v: int, weight: int):
        """Thêm cạnh vào đồ thị"""
        edge_key = f"{min(u, v)}-{max(u, v)}"
        self.edge_key_count[edge_key] += 1
        
        edge_type = "normal"
        if u == v:
            edge_type = "self-loop"
            self.stats.num_self_loops += 1
        elif self.edge_key_count[edge_key] > 1:
            edge_type = "parallel"
            self.stats.num_parallel_edges += 1
        
        # Thêm cạnh từ u đến v
        self.adj_list[u].append(GeneralEdge(u, v, weight, self.edge_id_counter, edge_type))
        
        # Nếu là đồ thị vô hướng và không phải vòng lặp
        if not self.is_directed and u != v:
            self.adj_list[v].append(GeneralEdge(v, u, weight, self.edge_id_counter, edge_type))
        
        self.stats.num_edges += 1
        self.stats.edge_type_count[edge_type] += 1
        
        direction = "có hướng " if self.is_directed else ""
        print(f"Thêm cạnh {direction}{u} -> {v} (trọng số: {weight}, "
              f"loại: {edge_type}, ID: {self.edge_id_counter})")
        
        self.edge_id_counter += 1
    
    def dijkstra_general(self, source: int):
        """Dijkstra tổng quát"""
        self.reset()
        
        heap = [(0, source)]
        self.dist[source] = 0
        
        graph_type = "có hướng" if self.is_directed else "vô hướng"
        print(f"\nDijkstra tổng quát từ đỉnh {source} trên đồ thị {graph_type}:")
        
        processed_vertices = 0
        
        while heap:
            current_dist, u = heapq.heappop(heap)
            
            if self.visited[u]:
                continue
                
            self.visited[u] = True
            self.in_current_component[u] = True
            processed_vertices += 1
            
            print(f"Bước {processed_vertices}: Xử lý đỉnh {u} (khoảng cách: {current_dist})")
            
            # Xử lý tất cả các cạnh từ u
            for edge in self.adj_list[u]:
                v = edge.to_vertex
                weight = edge.weight
                
                print(f"  Kiểm tra cạnh {u} -> {v} (trọng số: {weight}, loại: {edge.type})", end="")
                
                # Xử lý đặc biệt cho vòng lặp
                if edge.type == "self-loop":
                    print(" [Vòng lặp - bỏ qua]")
                    continue
                
                if not self.visited[v]:
                    new_dist = self.dist[u] + weight
                    
                    if new_dist < self.dist[v]:
                        self.dist[v] = new_dist
                        self.parent[v] = u
                        self.parent_edge_id[v] = edge.id
                        heapq.heappush(heap, (new_dist, v))
                        
                        print(f" [Cập nhật dist[{v}] = {new_dist}]")
                    else: 
                        print(" [Không cập nhật]")
                else:
                    print(" [Đỉnh đã thăm]")
        
        print(f"Đã xử lý {processed_vertices}/{self.num_vertices} đỉnh")
    
    def analyze_connectivity(self):
        """Phân tích tính liên thông"""
        self.stats.components = []
        global_visited = [False] * self.num_vertices
        
        for i in range(self.num_vertices):
            if not global_visited[i]:
                component = []
                self._dfs_component(i, global_visited, component)
                self.stats.components.append(component)
        
        self.stats.is_connected = (len(self.stats.components) == 1)
        
        print("\nPhân tích tính liên thông:")
        print(f"Số thành phần liên thông: {len(self.stats.components)}")
        
        for i, component in enumerate(self.stats.components):
            print(f"Thành phần {i + 1}: {{{', '.join(map(str, component))}}}")
    
    def _dfs_component(self, u: int, global_visited: List[bool], component: List[int]):
        """DFS để tìm thành phần liên thông"""
        global_visited[u] = True
        component.append(u)
        
        for edge in self.adj_list[u]:
            v = edge.to_vertex
            if not global_visited[v]:
                self._dfs_component(v, global_visited, component)
    
    def print_general_graph(self):
        """In đồ thị tổng quát"""
        graph_type = "có hướng" if self.is_directed else "vô hướng"
        print(f"\nĐồ thị tổng quát ({graph_type}):")
        
        for i in range(self.num_vertices):
            print(f"Đỉnh {i}: ", end="")
            
            # Nhóm cạnh theo đích và loại
            edge_groups = defaultdict(list)
            for edge in self.adj_list[i]:
                edge_groups[edge.to_vertex].append(edge)
            
            for dest, edges in edge_groups.items():
                print(f"{dest}", end="")
                if len(edges) > 1 or edges[0].type != "normal":
                    weights = []
                    for edge in edges:
                        weight_str = str(edge.weight)
                        if edge.type == "self-loop":
                            weight_str += "L"
                        elif edge.type == "parallel" and len(edges) > 1:
                            weight_str += "P"
                        weights.append(weight_str)
                    print(f"[{','.join(weights)}]", end="")
                else:
                    print(f"({edges[0].weight})", end="")
                print(" ", end="")
            print()
        print()
    
    def print_detailed_results(self, source: int):
        """In kết quả chi tiết"""
        print("\n=== KẾT QUẢ CHI TIẾT DIJKSTRA ===")
        graph_type = "có hướng" if self.is_directed else "vô hướng"
        print(f"Nguồn: {source} | Đồ thị: {graph_type}")
        print("-" * 70)
        
        headers = ["Đỉnh", "Khoảng cách", "Cha", "Cạnh ID", "Đường đi", "Trạng thái"]
        print(f"{headers[0]:<6} {headers[1]:<12} {headers[2]:<8} {headers[3]:<10} {headers[4]:<15} {headers[5]:<15}")
        print("-" * 70)
        
        for i in range(self.num_vertices):
            print(f"{i:<6}", end="")
            
            if self.dist[i] == float('inf'):
                print(f"{'∞':<12} {'-':<8} {'-':<10} {'Không đạt được':<15} {'Không liên thông':<15}")
            else:
                parent_str = "-" if self.parent[i] == -1 else str(self.parent[i])
                edge_id_str = "-" if self.parent_edge_id[i] == -1 else str(self.parent_edge_id[i])
                path_str = self._get_path_string(source, i)
                status = "Nguồn" if i == source else "Đạt được"
                
                print(f"{self.dist[i]:<12} {parent_str:<8} {edge_id_str:<10} {path_str:<15} {status:<15}")
        
        print("-" * 70)
    
    def _get_path_string(self, source: int, dest: int) -> str:
        """Lấy chuỗi biểu diễn đường đi"""
        if dest == source:
            return str(dest)
        if self.parent[dest] == -1:
            return "N/A"
        
        path = []
        current = dest
        
        while current != -1:
            path.append(current)
            current = self.parent[current]
        
        path.reverse()
        return "→".join(map(str, path))
    
    def print_graph_statistics(self):
        """In thống kê đồ thị"""
        print("\n=== THỐNG KÊ ĐỒ THỊ ===")
        print(f"Số đỉnh: {self.stats.num_vertices}")
        print(f"Số cạnh: {self.stats.num_edges}")
        graph_type = "Có hướng" if self.stats.is_directed else "Vô hướng"
        print(f"Loại đồ thị: {graph_type}")
        connected_str = "Có" if self.stats.is_connected else "Không"
        print(f"Liên thông: {connected_str}")
        print(f"Số thành phần liên thông: {len(self.stats.components)}")
        
        print("\nThống kê loại cạnh:")
        for edge_type, count in self.stats.edge_type_count.items():
            print(f"  {edge_type}: {count}")
        
        if self.stats.num_self_loops > 0:
            print(f"Có {self.stats.num_self_loops} vòng lặp")
        
        if self.stats.num_parallel_edges > 0:
            print("Có cạnh song song")
        
        print()
    
    def run_complete_analysis(self, source: int):
        """Chạy phân tích hoàn chỉnh"""
        print("=== PHÂN TÍCH HOÀN CHỈNH ĐỒ THỊ ===")
        
        # 1. In đồ thị
        self.print_general_graph()
        
        # 2. Thống kê đồ thị
        self.print_graph_statistics()
        
        # 3. Phân tích tính liên thông
        self.analyze_connectivity()
        
        # 4. Chạy Dijkstra
        self.dijkstra_general(source)
        
        # 5. In kết quả chi tiết
        self.print_detailed_results(source)
        
        # 6. Phân tích các trường hợp đặc biệt
        self.analyze_special_cases(source)
    
    def analyze_special_cases(self, source: int):
        """Phân tích trường hợp đặc biệt"""
        print("\n=== PHÂN TÍCH TRƯỜNG HỢP ĐẶC BIỆT ===")
        
        # Đỉnh không đạt được
        unreachable = [i for i in range(self.num_vertices) if self.dist[i] == float('inf')]
        
        if unreachable:
            print(f"Đỉnh không đạt được từ {source}: {', '.join(map(str, unreachable))}")
        
        # Đường đi dài nhất
        max_dist = 0
        farthest_vertex = -1
        for i in range(self.num_vertices):
            if self.dist[i] != float('inf') and self.dist[i] > max_dist:
                max_dist = self.dist[i]
                farthest_vertex = i
        
        if farthest_vertex != -1:
            print(f"Đỉnh xa nhất từ {source}: {farthest_vertex} (khoảng cách: {max_dist})")
        
        # Số đỉnh trong cùng thành phần liên thông
        reachable_count = sum(1 for d in self.dist if d != float('inf'))
        percentage = (100.0 * reachable_count / self.num_vertices)
        
        print(f"Đỉnh đạt được: {reachable_count}/{self.num_vertices} ({percentage:.1f}%)")
        print()
    
    def all_pairs_shortest_path(self):
        """Tất cả cặp đường đi ngắn nhất"""
        print("=== TẤT CẢ CẶP ĐƯỜNG ĐI NGẮN NHẤT ===")
        
        all_dist = []
        
        for source in range(self.num_vertices):
            self.dijkstra_general(source)
            all_dist.append(self.dist[:])
        
        # In ma trận khoảng cách
        print("\nMa trận khoảng cách ngắn nhất:")
        print(f"{'':>6}", end="")
        for j in range(self.num_vertices):
            print(f"{j:>6}", end="")
        print()
        
        for i in range(self.num_vertices):
            print(f"{i:>6}", end="")
            for j in range(self.num_vertices):
                if all_dist[i][j] == float('inf'):
                    print(f"{'∞':>6}", end="")
                else:
                    print(f"{all_dist[i][j]:>6}", end="")
            print()
        print()
    
    def find_shortest_path_between(self, source: int, dest: int) -> Tuple[float, List[int]]:
        """Tìm đường đi ngắn nhất giữa hai đỉnh cụ thể"""
        self.dijkstra_general(source)
        
        if self.dist[dest] == float('inf'):
            return (float('inf'), [])
        
        path = []
        current = dest
        
        while current != -1:
            path.append(current)
            current = self.parent[current]
        
        path.reverse()
        return (self.dist[dest], path)
    
    def test_graph_properties(self):
        """Kiểm tra các tính chất của đồ thị"""
        print("\n=== KIỂM TRA TÍNH CHẤT ĐỒ THỊ ===")
        
        # Kiểm tra đồ thị có chu trình không (chỉ với đồ thị có hướng)
        if self.is_directed:
            has_cycle = self._has_cycle_directed()
            print(f"Có chu trình: {'Có' if has_cycle else 'Không'}")
        
        # Tìm diameter của đồ thị (đường đi dài nhất giữa các cặp đỉnh)
        max_shortest_distance = 0
        diameter_pair = None
        
        for i in range(self.num_vertices):
            self.dijkstra_general(i)
            for j in range(self.num_vertices):
                if self.dist[j] != float('inf') and self.dist[j] > max_shortest_distance:
                    max_shortest_distance = self.dist[j]
                    diameter_pair = (i, j)
        
        if diameter_pair:
            print(f"Đường kính đồ thị: {max_shortest_distance} (từ {diameter_pair[0]} đến {diameter_pair[1]})")
        else:
            print("Đồ thị không liên thông - không có đường kính")
        
        # Tìm các đỉnh cầu (articulation points) - đơn giản hóa
        print("Phân tích hoàn tất.")
        print()
    
    def _has_cycle_directed(self) -> bool:
        """Kiểm tra chu trình trong đồ thị có hướng bằng DFS"""
        color = [0] * self.num_vertices  # 0: white, 1: gray, 2: black
        
        def dfs_cycle(u):
            color[u] = 1  # gray
            
            for edge in self.adj_list[u]:
                v = edge.to_vertex
                if color[v] == 1:  # back edge - found cycle
                    return True
                elif color[v] == 0 and dfs_cycle(v):
                    return True
            
            color[u] = 2  # black
            return False
        
        for i in range(self.num_vertices):
            if color[i] == 0:
                if dfs_cycle(i):
                    return True
        
        return False

def demonstrate_general_dijkstra():
    """Demo Dijkstra tổng quát"""
    print("=== DEMO DIJKSTRA CHO ĐỒ THỊ TỔNG QUÁT ===\n")
    
    # Test case 1: Đồ thị vô hướng với cạnh song song
    print(">>> TEST CASE 1: Đồ thị vô hướng với cạnh song song <<<")
    graph1 = GeneralDijkstra(5, is_directed=False)
    
    graph1.add_edge(0, 1, 4)
    graph1.add_edge(0, 1, 2)  # Cạnh song song
    graph1.add_edge(0, 2, 3)
    graph1.add_edge(1, 3, 1)
    graph1.add_edge(2, 3, 5)
    graph1.add_edge(3, 4, 2)
    graph1.add_edge(1, 1, 3)  # Vòng lặp
    
    graph1.run_complete_analysis(0)
    graph1.test_graph_properties()
    
    print("\n" + "="*60 + "\n")
    
    # Test case 2: Đồ thị có hướng không liên thông
    print(">>> TEST CASE 2: Đồ thị có hướng không liên thông <<<")
    graph2 = GeneralDijkstra(6, is_directed=True)
    
    graph2.add_edge(0, 1, 2)
    graph2.add_edge(1, 2, 3)
    graph2.add_edge(3, 4, 1)
    graph2.add_edge(4, 5, 4)
    graph2.add_edge(2, 2, 1)  # Vòng lặp
    graph2.add_edge(4, 3, 2)  # Tạo chu trình
    
    graph2.run_complete_analysis(0)
    graph2.test_graph_properties()
    
    print("\n" + "="*60 + "\n")
    
    # Test case 3: Tìm đường đi cụ thể
    print(">>> TEST CASE 3: Tìm đường đi cụ thể <<<")
    dist, path = graph1.find_shortest_path_between(0, 4)
    if path:
        print(f"Đường đi ngắn nhất từ 0 đến 4:")
        print(f"Độ dài: {dist}")
        print(f"Đường đi: {' → '.join(map(str, path))}")
    else:
        print("Không có đường đi từ 0 đến 4")
    
    print("\n" + "="*60 + "\n")
    
    # Test case 4: Ma trận khoảng cách cho đồ thị nhỏ
    print(">>> TEST CASE 4: Ma trận khoảng cách <<<")
    small_graph = GeneralDijkstra(4, is_directed=False)
    small_graph.add_edge(0, 1, 1)
    small_graph.add_edge(1, 2, 2)
    small_graph.add_edge(2, 3, 3)
    small_graph.add_edge(0, 3, 10)
    
    small_graph.all_pairs_shortest_path()

def interactive_demo():
    """Demo tương tác cho người dùng"""
    print("\n=== DEMO TƯƠNG TÁC ===")
    print("Tạo đồ thị tùy chỉnh:")
    
    try:
        n = int(input("Nhập số đỉnh: "))
        is_directed = input("Đồ thị có hướng? (y/n): ").lower() == 'y'
        
        graph = GeneralDijkstra(n, is_directed)
        
        print("\nNhập các cạnh (format: u v weight), nhập -1 để kết thúc:")
        while True:
            edge_input = input("Cạnh: ").strip()
            if edge_input == "-1":
                break
            
            try:
                u, v, w = map(int, edge_input.split())
                if 0 <= u < n and 0 <= v < n and w >= 0:
                    graph.add_edge(u, v, w)
                else:
                    print("Đỉnh hoặc trọng số không hợp lệ!")
            except ValueError:
                print("Format không đúng! Vui lòng nhập: u v weight")
        
        source = int(input(f"\nNhập đỉnh nguồn (0-{n-1}): "))
        if 0 <= source < n:
            graph.run_complete_analysis(source)
        else:
            print("Đỉnh nguồn không hợp lệ!")
            
    except ValueError:
        print("Dữ liệu nhập không hợp lệ!")
    except KeyboardInterrupt:
        print("\nDemo bị hủy bởi người dùng.")

if __name__ == "__main__":
    # Chạy demo tự động
    demonstrate_general_dijkstra()
    
    # Hỏi người dùng có muốn chạy demo tương tác không
    print("\n" + "="*60)
    choice = input("Bạn có muốn chạy demo tương tác? (y/n): ").lower()
    if choice == 'y':
        interactive_demo()
    