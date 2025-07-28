from collections import deque, defaultdict
from typing import List, Dict, Set, Tuple, Optional

class MultigraphBFS:
    """BFS cho multigraph (đa đồ thị)"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        # Sử dụng list để lưu nhiều cạnh giữa hai đỉnh
        self.adj_list = [[] for _ in range(num_vertices)]
        self.edge_count = defaultdict(int)  # Đếm số cạnh giữa hai đỉnh
        self.reset_arrays()
    
    def reset_arrays(self):
        """Reset các mảng trạng thái"""
        self.visited = [False] * self.num_vertices
        self.distance = [float('inf')] * self.num_vertices
        self.parent = [-1] * self.num_vertices
        self.bfs_order = []
    
    def add_edge(self, u: int, v: int):
        """Thêm cạnh vào multigraph"""
        if not (0 <= u < self.num_vertices and 0 <= v < self.num_vertices):
            print(f"Cạnh ({u},{v}) không hợp lệ!")
            return
            
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)
        
        # Đếm số cạnh giữa u và v
        edge = tuple(sorted([u, v]))
        self.edge_count[edge] += 1
        
        print(f"Thêm cạnh ({u},{v}) - Số cạnh giữa {u} và {v}: {self.edge_count[edge]}")
    
    def bfs(self, start: int) -> List[int]:
        """
        Thực hiện BFS trên multigraph
        
        Args:
            start: Đỉnh bắt đầu
            
        Returns:
            Thứ tự duyệt BFS
        """
        if not (0 <= start < self.num_vertices):
            print(f"Đỉnh bắt đầu {start} không hợp lệ!")
            return []
            
        self.reset_arrays()
        
        queue = deque([start])
        self.visited[start] = True
        self.distance[start] = 0
        
        print(f"BFS trên Multigraph từ đỉnh {start}:")
        print("Thứ tự duyệt: ", end="")
        
        while queue:
            u = queue.popleft()
            self.bfs_order.append(u)
            print(u, end=" ")
            
            # Lấy danh sách đỉnh kề duy nhất để tránh duyệt trùng
            # Sử dụng set để loại bỏ trùng lặp
            unique_neighbors = set(self.adj_list[u])
            
            for v in sorted(unique_neighbors):
                if not self.visited[v]:
                    self.visited[v] = True
                    self.distance[v] = self.distance[u] + 1
                    self.parent[v] = u
                    queue.append(v)
        
        print("\n")
        return self.bfs_order.copy()
    
    def bfs_complete(self) -> Dict[int, List[int]]:
        """
        BFS toàn bộ đồ thị (xử lý thành phần liên thông)
        
        Returns:
            Dictionary chứa các thành phần liên thông
        """
        self.reset_arrays()
        components = {}
        component_count = 0
        
        print("BFS toàn bộ multigraph:")
        
        for i in range(self.num_vertices):
            if not self.visited[i]:
                component_count += 1
                component = self._bfs_component(i)
                components[component_count] = component
                print(f"Thành phần liên thông {component_count}: {' '.join(map(str, component))}")
        
        print(f"Tổng số thành phần liên thông: {component_count}\n")
        return components
    
    def _bfs_component(self, start: int) -> List[int]:
        """BFS cho một thành phần liên thông"""
        component = []
        queue = deque([start])
        self.visited[start] = True
        self.distance[start] = 0
        
        while queue:
            u = queue.popleft()
            component.append(u)
            
            unique_neighbors = set(self.adj_list[u])
            for v in sorted(unique_neighbors):
                if not self.visited[v]:
                    self.visited[v] = True
                    self.distance[v] = self.distance[u] + 1
                    self.parent[v] = u
                    queue.append(v)
        
        return component
    
    def get_shortest_path(self, start: int, target: int) -> List[int]:
        """
        Tìm đường đi ngắn nhất từ start đến target
        
        Args:
            start: Đỉnh bắt đầu
            target: Đỉnh đích
            
        Returns:
            Đường đi ngắn nhất (rỗng nếu không có đường đi)
        """
        self.bfs(start)
        
        if self.distance[target] == float('inf'):
            return []  # Không có đường đi
        
        # Tái tạo đường đi từ mảng parent
        path = []
        current = target
        while current != -1:
            path.append(current)
            current = self.parent[current]
        
        path.reverse()
        return path
    
    def print_distances(self, start: int):
        """In thông tin khoảng cách"""
        print(f"Khoảng cách từ đỉnh {start}:")
        print(f"{'Đỉnh':<6} {'Khoảng cách':<12} {'Cha':<10}")
        print("-" * 28)
        
        for i in range(self.num_vertices):
            dist_str = "INF" if self.distance[i] == float('inf') else str(self.distance[i])
            print(f"{i:<6} {dist_str:<12} {self.parent[i]:<10}")
        print()
    
    def print_bfs_tree(self, start: int):
        """In cây BFS"""
        print(f"Cây BFS từ đỉnh {start}:")
        
        tree_edges = []
        for i in range(self.num_vertices):
            if self.parent[i] != -1:
                tree_edges.append((self.parent[i], i))
        
        if tree_edges:
            for parent, child in tree_edges:
                print(f"{parent} -> {child}")
        else:
            print("Không có cây BFS (đồ thị rỗng hoặc chỉ có một đỉnh)")
        print()
    
    def print_multiple_edges(self):
        """In thông tin về các cạnh bội"""
        print("Các cạnh bội trong multigraph:")
        has_multiple = False
        
        for edge, count in sorted(self.edge_count.items()):
            if count > 1:
                print(f"Cạnh {edge}: {count} cạnh")
                has_multiple = True
        
        if not has_multiple:
            print("Không có cạnh bội")
        print()
    
    def get_edge_multiplicity(self, u: int, v: int) -> int:
        """Lấy số lượng cạnh giữa u và v"""
        edge = tuple(sorted([u, v]))
        return self.edge_count.get(edge, 0)
    
    def print_graph(self):
        """In biểu diễn multigraph"""
        print("Biểu diễn Multigraph (danh sách kề):")
        for i in range(self.num_vertices):
            neighbors = ' '.join(map(str, self.adj_list[i]))
            print(f"{i}: {neighbors}")
        print()
    
    def get_total_edges(self) -> int:
        """Tính tổng số cạnh (kể cả cạnh bội)"""
        return sum(self.edge_count.values())
    
    def is_connected(self) -> bool:
        """Kiểm tra đồ thị có liên thông không"""
        if self.num_vertices == 0:
            return True
            
        self.bfs(0)
        return all(self.visited)
    
    def find_all_paths_between(self, start: int, end: int, max_length: int = 10) -> List[List[int]]:
        """
        Tìm tất cả đường đi từ start đến end (có giới hạn độ dài)
        
        Args:
            start: Đỉnh bắt đầu
            end: Đỉnh kết thúc  
            max_length: Độ dài đường đi tối đa
            
        Returns:
            Danh sách các đường đi
        """
        all_paths = []
        
        def dfs_paths(current: int, target: int, path: List[int], visited: Set[int]):
            if len(path) > max_length:
                return
                
            if current == target:
                all_paths.append(path.copy())
                return
            
            # Lấy đỉnh kề duy nhất
            unique_neighbors = set(self.adj_list[current])
            for neighbor in unique_neighbors:
                if neighbor not in visited:
                    path.append(neighbor)
                    visited.add(neighbor)
                    dfs_paths(neighbor, target, path, visited)
                    path.pop()
                    visited.remove(neighbor)
        
        if start == end:
            return [[start]]
        
        dfs_paths(start, end, [start], {start})
        return all_paths
    
    def get_graph_statistics(self) -> Dict:
        """Lấy thống kê về đồ thị"""
        stats = {
            'num_vertices': self.num_vertices,
            'total_edges': self.get_total_edges(),
            'unique_edges': len(self.edge_count),
            'multiple_edges': sum(1 for count in self.edge_count.values() if count > 1),
            'is_connected': self.is_connected(),
            'components': len(self.bfs_complete())
        }
        return stats


class MultigraphUtils:
    """Các hàm tiện ích cho Multigraph"""
    
    @staticmethod
    def create_sample_multigraph1() -> MultigraphBFS:
        """Tạo multigraph mẫu 1"""
        graph = MultigraphBFS(5)
        
        # Thêm cạnh bình thường
        graph.add_edge(0, 1)
        graph.add_edge(1, 2)
        graph.add_edge(2, 3)
        graph.add_edge(3, 4)
        
        # Thêm cạnh bội
        graph.add_edge(0, 1)  # Cạnh thứ 2 giữa 0 và 1
        graph.add_edge(1, 2)  # Cạnh thứ 2 giữa 1 và 2
        graph.add_edge(0, 2)  # Cạnh mới
        
        return graph
    
    @staticmethod
    def create_sample_multigraph2() -> MultigraphBFS:
        """Tạo multigraph mẫu 2 - không liên thông"""
        graph = MultigraphBFS(7)
        
        # Thành phần 1
        graph.add_edge(0, 1)
        graph.add_edge(0, 1)  # Cạnh bội
        graph.add_edge(1, 2)
        
        # Thành phần 2
        graph.add_edge(3, 4)
        graph.add_edge(3, 4)  # Cạnh bội
        graph.add_edge(4, 5)
        graph.add_edge(3, 5)
        
        # Đỉnh cô lập
        # Đỉnh 6 không có cạnh nào
        
        return graph
    
    @staticmethod
    def create_complete_multigraph(n: int, multiplicity: int = 2) -> MultigraphBFS:
        """Tạo đồ thị đầy đủ với cạnh bội"""
        graph = MultigraphBFS(n)
        
        for i in range(n):
            for j in range(i + 1, n):
                for _ in range(multiplicity):
                    graph.add_edge(i, j)
        
        return graph


def demonstrate_multigraph_bfs():
    """Demo các tính năng của Multigraph BFS"""
    print("=== DEMO BFS TRÊN MULTIGRAPH ===\n")
    
    # Demo 1: Multigraph liên thông
    print("1. MULTIGRAPH LIÊN THÔNG:")
    graph1 = MultigraphUtils.create_sample_multigraph1()
    graph1.print_graph()
    graph1.print_multiple_edges()
    
    # BFS từ đỉnh 0
    graph1.bfs(0)
    graph1.print_distances(0)
    graph1.print_bfs_tree(0)
    
    # Tìm đường đi ngắn nhất
    print("Đường đi ngắn nhất từ 0 đến 4:")
    path = graph1.get_shortest_path(0, 4)
    if path:
        path_str = ' -> '.join(map(str, path))
        print(f"{path_str} (Độ dài: {len(path) - 1})")
    else:
        print("Không có đường đi")
    print()
    
    # Thống kê đồ thị
    stats1 = graph1.get_graph_statistics()
    print("Thống kê đồ thị 1:")
    for key, value in stats1.items():
        print(f"  {key}: {value}")
    print()
    
    # Demo 2: Multigraph không liên thông
    print("2. MULTIGRAPH KHÔNG LIÊN THÔNG:")
    graph2 = MultigraphUtils.create_sample_multigraph2()
    graph2.print_graph()
    graph2.print_multiple_edges()
    graph2.bfs_complete()
    
    stats2 = graph2.get_graph_statistics()
    print("Thống kê đồ thị 2:")
    for key, value in stats2.items():
        print(f"  {key}: {value}")
    print()
    
    # Demo 3: Complete multigraph
    print("3. COMPLETE MULTIGRAPH (4 đỉnh, mỗi cạnh có 2 bản sao):")
    complete_graph = MultigraphUtils.create_complete_multigraph(4, 2)
    complete_graph.print_graph()
    complete_graph.print_multiple_edges()
    complete_graph.bfs(0)
    
    stats3 = complete_graph.get_graph_statistics()
    print("Thống kê complete multigraph:")
    for key, value in stats3.items():
        print(f"  {key}: {value}")
    print()


def interactive_demo():
    """Demo tương tác với người dùng"""
    print("=== DEMO TƯƠNG TÁC MULTIGRAPH ===")
    
    try:
        n = int(input("Nhập số đỉnh: "))
        if n <= 0:
            print("Số đỉnh phải là số dương!")
            return
        
        m = int(input("Nhập số cạnh: "))
        if m < 0:
            print("Số cạnh không thể âm!")
            return
        
        user_graph = MultigraphBFS(n)
        
        print(f"Nhập {m} cạnh (u v), có thể có cạnh trùng lặp:")
        for i in range(m):
            try:
                u, v = map(int, input(f"Cạnh {i+1}: ").split())
                if 0 <= u < n and 0 <= v < n:
                    user_graph.add_edge(u, v)
                else:
                    print(f"Cạnh ({u}, {v}) không hợp lệ! Đỉnh phải từ 0 đến {n-1}")
                    return
            except ValueError:
                print("Vui lòng nhập hai số nguyên!")
                return
        
        start = int(input("Nhập đỉnh bắt đầu BFS: "))
        if not (0 <= start < n):
            print(f"Đỉnh bắt đầu phải từ 0 đến {n-1}!")
            return
        
        print("\nKết quả:")
        user_graph.print_graph()
        user_graph.print_multiple_edges()
        user_graph.bfs(start)
        user_graph.print_distances(start)
        user_graph.print_bfs_tree(start)
        
        # Thống kê
        stats = user_graph.get_graph_statistics()
        print("Thống kê đồ thị:")
        for key, value in stats.items():
            print(f"  {key}: {value}")
        
        # Tùy chọn bổ sung
        while True:
            print("\nCác tùy chọn bổ sung:")
            print("1. Tìm đường đi ngắn nhất")
            print("2. Hiển thị tất cả thành phần liên thông")
            print("3. Kiểm tra số lượng cạnh giữa hai đỉnh")
            print("4. Tìm tất cả đường đi giữa hai đỉnh")
            print("0. Thoát")
            
            choice = input("Chọn tùy chọn (0-4): ").strip()
            
            if choice == '0':
                break
            elif choice == '1':
                target = int(input("Nhập đỉnh đích: "))
                if 0 <= target < n:
                    path = user_graph.get_shortest_path(start, target)
                    if path:
                        path_str = ' -> '.join(map(str, path))
                        print(f"Đường đi ngắn nhất từ {start} đến {target}: {path_str}")
                        print(f"Độ dài: {len(path) - 1}")
                    else:
                        print(f"Không có đường đi từ {start} đến {target}")
                else:
                    print("Đỉnh đích không hợp lệ!")
            
            elif choice == '2':
                components = user_graph.bfs_complete()
                print(f"Số thành phần liên thông: {len(components)}")
            
            elif choice == '3':
                u = int(input("Nhập đỉnh u: "))
                v = int(input("Nhập đỉnh v: "))
                if 0 <= u < n and 0 <= v < n:
                    count = user_graph.get_edge_multiplicity(u, v)
                    print(f"Số cạnh giữa {u} và {v}: {count}")
                else:
                    print("Đỉnh không hợp lệ!")
            
            elif choice == '4':
                u = int(input("Nhập đỉnh bắt đầu: "))
                v = int(input("Nhập đỉnh kết thúc: "))
                if 0 <= u < n and 0 <= v < n:
                    paths = user_graph.find_all_paths_between(u, v)
                    if paths:
                        print(f"Tất cả đường đi từ {u} đến {v}:")
                        for i, path in enumerate(paths, 1):
                            path_str = ' -> '.join(map(str, path))
                            print(f"  {i}: {path_str}")
                    else:
                        print(f"Không có đường đi từ {u} đến {v}")
                else:
                    print("Đỉnh không hợp lệ!")
            
            else:
                print("Tùy chọn không hợp lệ!")
    
    except ValueError:
        print("Vui lòng nhập số nguyên hợp lệ!")
    except KeyboardInterrupt:
        print("\nChương trình bị ngắt bởi người dùng.")


if __name__ == "__main__":
    # Chạy demo tự động
    demonstrate_multigraph_bfs()
    
    # Chạy demo tương tác
    print("\n" + "="*60)
    interactive_demo()