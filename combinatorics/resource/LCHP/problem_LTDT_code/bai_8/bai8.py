from collections import deque, defaultdict
from typing import List, Tuple, Dict, Set, Optional

class SimpleBFS:
    """
    Lớp cài đặt thuật toán BFS cho Simple Graph (Bài 8)
    """
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_list = defaultdict(list)
        self.reset_arrays()
    
    def reset_arrays(self):
        """Reset các mảng trạng thái"""
        self.visited = [False] * self.num_vertices
        self.distance = [float('inf')] * self.num_vertices
        self.parent = [-1] * self.num_vertices
        self.bfs_order = []
    
    def add_edge(self, u: int, v: int):
        """Thêm cạnh vào đồ thị vô hướng"""
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)
    
    def bfs(self, start: int) -> List[int]:
        """
        Thuật toán BFS chính
        
        Args:
            start: Đỉnh bắt đầu
            
        Returns:
            Thứ tự duyệt BFS
        """
        self.reset_arrays()
        
        queue = deque([start])
        self.visited[start] = True
        self.distance[start] = 0
        
        print(f"Bắt đầu BFS từ đỉnh {start}:")
        print("Thứ tự duyệt: ", end="")
        
        while queue:
            u = queue.popleft()
            
            # Xử lý đỉnh u
            self.bfs_order.append(u)
            print(u, end=" ")
            
            # Duyệt tất cả đỉnh kề với u
            for v in sorted(self.adj_list[u]):  # Sort để đảm bảo thứ tự nhất quán
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
        
        print("BFS toàn bộ đồ thị:")
        
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
            
            for v in sorted(self.adj_list[u]):
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
        
        for i in range(self.num_vertices):
            if self.parent[i] != -1:
                print(f"{self.parent[i]} -> {i}")
        print()
    
    def is_connected(self) -> bool:
        """Kiểm tra đồ thị có liên thông không"""
        self.bfs(0)
        return all(self.visited)
    
    def find_farthest_vertex(self, start: int) -> Tuple[int, int]:
        """
        Tìm đỉnh xa nhất từ start
        
        Returns:
            Tuple (đỉnh xa nhất, khoảng cách)
        """
        self.bfs(start)
        
        max_dist = -1
        farthest_vertex = -1
        
        for i in range(self.num_vertices):
            if self.distance[i] != float('inf') and self.distance[i] > max_dist:
                max_dist = self.distance[i]
                farthest_vertex = i
        
        return farthest_vertex, max_dist
    
    def print_graph(self):
        """In biểu diễn đồ thị"""
        print("Biểu diễn đồ thị (danh sách kề):")
        for i in range(self.num_vertices):
            neighbors = ' '.join(map(str, sorted(self.adj_list[i])))
            print(f"{i}: {neighbors}")
        print()
    
    def get_levels(self, start: int) -> Dict[int, List[int]]:
        """
        Lấy các mức trong BFS tree
        
        Returns:
            Dictionary: {level: [list of vertices]}
        """
        self.bfs(start)
        levels = defaultdict(list)
        
        for i in range(self.num_vertices):
            if self.distance[i] != float('inf'):
                levels[self.distance[i]].append(i)
        
        return dict(levels)


def create_sample_graph() -> SimpleBFS:
    """Tạo đồ thị mẫu"""
    graph = SimpleBFS(6)
    
    edges = [(0, 1), (0, 2), (1, 3), (2, 4), (3, 5), (4, 5)]
    for u, v in edges:
        graph.add_edge(u, v)
    
    return graph


def demonstrate_simple_bfs():
    """Demo BFS cho Simple Graph"""
    print("=== BÀI 8: BFS CHO SIMPLE GRAPH ===\n")
    
    # Tạo đồ thị mẫu
    graph = create_sample_graph()
    graph.print_graph()
    
    # BFS từ đỉnh 0
    graph.bfs(0)
    graph.print_distances(0)
    graph.print_bfs_tree(0)
    
    # Tìm đường đi ngắn nhất
    print("Đường đi ngắn nhất từ 0 đến 5:")
    path = graph.get_shortest_path(0, 5)
    if path:
        path_str = ' -> '.join(map(str, path))
        print(f"{path_str} (Độ dài: {len(path) - 1})")
    else:
        print("Không có đường đi")
    print()
    
    # Hiển thị các mức
    levels = graph.get_levels(0)
    print("Các mức trong BFS tree:")
    for level, vertices in sorted(levels.items()):
        print(f"Mức {level}: {vertices}")
    print()
    
    # Kiểm tra liên thông
    print(f"Đồ thị có liên thông không? {'Có' if graph.is_connected() else 'Không'}")
    
    # Tìm đỉnh xa nhất
    farthest, max_dist = graph.find_farthest_vertex(0)
    print(f"Đỉnh xa nhất từ 0: {farthest} (khoảng cách: {max_dist})\n")


def interactive_demo():
    """Demo tương tác với người dùng"""
    print("=== DEMO TƯƠNG TÁC ===")
    
    try:
        n, m = map(int, input("Nhập số đỉnh và số cạnh: ").split())
        
        if n <= 0 or m < 0:
            print("Số đỉnh và cạnh phải là số dương!")
            return
        
        user_graph = SimpleBFS(n)
        
        print(f"Nhập {m} cạnh (u v):")
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
        user_graph.bfs(start)
        user_graph.print_distances(start)
        user_graph.print_bfs_tree(start)
        
    except ValueError:
        print("Vui lòng nhập số nguyên hợp lệ!")
    except KeyboardInterrupt:
        print("\nChương trình bị ngắt bởi người dùng.")


if __name__ == "__main__":
    # Chạy demo tự động
    demonstrate_simple_bfs()
    
    # Chạy demo tương tác
    print("=" * 50)
    interactive_demo()