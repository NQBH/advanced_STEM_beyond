from collections import deque, defaultdict
from typing import List, Dict, Set, Tuple

class GeneralGraphBFS:
    """BFS cho general graph (đồ thị tổng quát)"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]
        self.edge_count = defaultdict(int)
        self.self_loops = set()  # Lưu các đỉnh có khuyên
        self.reset_arrays()
    
    def reset_arrays(self):
        self.visited = [False] * self.num_vertices
        self.distance = [float('inf')] * self.num_vertices
        self.parent = [-1] * self.num_vertices
    
    def add_edge(self, u: int, v: int):
        """Thêm cạnh vào general graph"""
        self.adj_list[u].append(v)
        
        if u != v:  # Không phải khuyên
            self.adj_list[v].append(u)
        else:  # Là khuyên
            self.self_loops.add(u)
            print(f"Thêm khuyên tại đỉnh {u}")
        
        # Đếm số cạnh
        edge = tuple(sorted([u, v]))
        self.edge_count[edge] += 1
        
        if u != v:
            print(f"Thêm cạnh ({u},{v}) - Số cạnh: {self.edge_count[edge]}")
    
    def bfs(self, start: int):
        """BFS trên general graph"""
        self.reset_arrays()
        
        queue = deque([start])
        self.visited[start] = True
        self.distance[start] = 0
        
        print(f"BFS trên General Graph từ đỉnh {start}:")
        
        # Kiểm tra khuyên tại đỉnh bắt đầu
        if start in self.self_loops:
            print(f"Đỉnh bắt đầu {start} có khuyên!")
        
        print("Thứ tự duyệt: ", end="")
        
        while queue:
            u = queue.popleft()
            print(u, end=" ")
            
            # Lọc ra các đỉnh kề duy nhất (loại bỏ khuyên và trùng lặp)
            unique_neighbors = set()
            for v in self.adj_list[u]:
                if v != u:  # Bỏ qua khuyên trong BFS
                    unique_neighbors.add(v)
            
            for v in sorted(unique_neighbors):
                if not self.visited[v]:
                    self.visited[v] = True
                    self.distance[v] = self.distance[u] + 1
                    self.parent[v] = u
                    queue.append(v)
        
        print("\n")
    
    def print_graph_info(self):
        """In thông tin về đồ thị"""
        print("Thông tin General Graph:")
        print(f"Số đỉnh: {self.num_vertices}")
        print(f"Số đỉnh có khuyên: {len(self.self_loops)}")
        
        if self.self_loops:
            print(f"Các đỉnh có khuyên: {sorted(self.self_loops)}")
        
        print("Các cạnh bội:")
        for edge, count in self.edge_count.items():
            if count > 1:
                print(f"Cạnh {edge}: {count} cạnh")
        print()
    
    def check_special_properties(self):
        """Kiểm tra tính chất đặc biệt"""
        print("Kiểm tra tính chất đặc biệt:")
        
        # Kiểm tra có phải simple graph không
        is_simple = len(self.self_loops) == 0
        for count in self.edge_count.values():
            if count > 1:
                is_simple = False
                break
        
        print(f"Là simple graph: {'Có' if is_simple else 'Không'}")
        print(f"Là multigraph: {'Có' if len(self.self_loops) == 0 else 'Không'}")
        print("Là general graph: Có")
        print()
    
    def get_self_loops(self) -> Set[int]:
        """Lấy danh sách các đỉnh có khuyên"""
        return self.self_loops.copy()
    
    def has_multiple_edges(self, u: int, v: int) -> bool:
        """Kiểm tra có nhiều cạnh giữa u và v không"""
        edge = tuple(sorted([u, v]))
        return self.edge_count.get(edge, 0) > 1
    
    def print_graph(self):
        """In biểu diễn general graph"""
        print("Biểu diễn General Graph:")
        for i in range(self.num_vertices):
            neighbors = ' '.join(map(str, self.adj_list[i]))
            print(f"{i}: {neighbors}")
        print()
    
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
    
    def is_connected(self) -> bool:
        """Kiểm tra đồ thị có liên thông không"""
        self.bfs(0)
        return all(self.visited)
    
    def get_connected_components(self) -> List[List[int]]:
        """Lấy tất cả các thành phần liên thông"""
        self.reset_arrays()
        components = []
        
        for i in range(self.num_vertices):
            if not self.visited[i]:
                component = self._bfs_component(i)
                components.append(component)
        
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
            
            # Lọc ra các đỉnh kề duy nhất (loại bỏ khuyên và trùng lặp)
            unique_neighbors = set()
            for v in self.adj_list[u]:
                if v != u:  # Bỏ qua khuyên
                    unique_neighbors.add(v)
            
            for v in sorted(unique_neighbors):
                if not self.visited[v]:
                    self.visited[v] = True
                    self.distance[v] = self.distance[u] + 1
                    self.parent[v] = u
                    queue.append(v)
        
        return component


def demonstrate_general_graph():
    """Demo chức năng của General Graph BFS"""
    print("=== DEMO GENERAL GRAPH BFS ===\n")
    
    # Tạo đồ thị mẫu
    print("1. TẠO ĐỒ THỊ GENERAL GRAPH:")
    graph = GeneralGraphBFS(6)
    
    # Thêm cạnh bình thường
    graph.add_edge(0, 1)
    graph.add_edge(1, 2)
    graph.add_edge(2, 3)
    
    # Thêm cạnh bội
    graph.add_edge(0, 1)  # Cạnh thứ 2 giữa 0 và 1
    graph.add_edge(1, 2)  # Cạnh thứ 2 giữa 1 và 2
    
    # Thêm khuyên
    graph.add_edge(2, 2)  # Khuyên tại đỉnh 2
    graph.add_edge(4, 4)  # Khuyên tại đỉnh 4
    
    # Thêm cạnh riêng lẻ
    graph.add_edge(3, 4)
    graph.add_edge(4, 5)
    
    print("\n2. THÔNG TIN ĐỒ THỊ:")
    graph.print_graph()
    graph.print_graph_info()
    graph.check_special_properties()
    
    print("3. THỰC HIỆN BFS:")
    graph.bfs(0)
    graph.print_distances(0)
    graph.print_bfs_tree(0)
    
    print("4. TÌM ĐƯỜNG ĐI NGẮN NHẤT:")
    path = graph.get_shortest_path(0, 5)
    if path:
        path_str = ' -> '.join(map(str, path))
        print(f"Đường đi ngắn nhất từ 0 đến 5: {path_str}")
        print(f"Độ dài: {len(path) - 1}")
    else:
        print("Không có đường đi từ 0 đến 5")
    print()
    
    print("5. KIỂM TRA TÍNH LIÊN THÔNG:")
    print(f"Đồ thị {'liên thông' if graph.is_connected() else 'không liên thông'}")
    
    components = graph.get_connected_components()
    print(f"Số thành phần liên thông: {len(components)}")
    for i, component in enumerate(components, 1):
        print(f"Thành phần {i}: {component}")
    print()


def interactive_demo():
    """Demo tương tác với người dùng"""
    print("=== DEMO TƯƠNG TÁC GENERAL GRAPH ===")
    
    try:
        n = int(input("Nhập số đỉnh: "))
        if n <= 0:
            print("Số đỉnh phải là số dương!")
            return
        
        graph = GeneralGraphBFS(n)
        
        print("\nNhập các cạnh (nhập -1 -1 để kết thúc):")
        print("Lưu ý: Cạnh (u, u) sẽ tạo khuyên tại đỉnh u")
        
        edge_count = 0
        while True:
            try:
                u, v = map(int, input(f"Cạnh {edge_count + 1}: ").split())
                
                if u == -1 and v == -1:
                    break
                
                if 0 <= u < n and 0 <= v < n:
                    graph.add_edge(u, v)
                    edge_count += 1
                else:
                    print(f"Đỉnh phải từ 0 đến {n-1}!")
            except ValueError:
                print("Vui lòng nhập hai số nguyên!")
                continue
        
        if edge_count == 0:
            print("Không có cạnh nào được thêm!")
            return
        
        start = int(input("Nhập đỉnh bắt đầu BFS: "))
        if not (0 <= start < n):
            print(f"Đỉnh bắt đầu phải từ 0 đến {n-1}!")
            return
        
        print("\n" + "="*50)
        print("KẾT QUẢ:")
        graph.print_graph()
        graph.print_graph_info()
        graph.check_special_properties()
        graph.bfs(start)
        graph.print_distances(start)
        graph.print_bfs_tree(start)
        
        # Menu tùy chọn
        while True:
            print("\nCác tùy chọn bổ sung:")
            print("1. Tìm đường đi ngắn nhất")
            print("2. Kiểm tra tính liên thông")
            print("3. Hiển thị thành phần liên thông")
            print("4. Kiểm tra cạnh bội")
            print("5. Hiển thị khuyên")
            print("0. Thoát")
            
            choice = input("Chọn tùy chọn (0-5): ").strip()
            
            if choice == '0':
                break
            elif choice == '1':
                target = int(input("Nhập đỉnh đích: "))
                if 0 <= target < n:
                    path = graph.get_shortest_path(start, target)
                    if path:
                        path_str = ' -> '.join(map(str, path))
                        print(f"Đường đi ngắn nhất từ {start} đến {target}: {path_str}")
                        print(f"Độ dài: {len(path) - 1}")
                    else:
                        print(f"Không có đường đi từ {start} đến {target}")
                else:
                    print("Đỉnh đích không hợp lệ!")
            
            elif choice == '2':
                print(f"Đồ thị {'liên thông' if graph.is_connected() else 'không liên thông'}")
            
            elif choice == '3':
                components = graph.get_connected_components()
                print(f"Số thành phần liên thông: {len(components)}")
                for i, component in enumerate(components, 1):
                    print(f"Thành phần {i}: {component}")
            
            elif choice == '4':
                u = int(input("Nhập đỉnh u: "))
                v = int(input("Nhập đỉnh v: "))
                if 0 <= u < n and 0 <= v < n:
                    if graph.has_multiple_edges(u, v):
                        edge = tuple(sorted([u, v]))
                        count = graph.edge_count[edge]
                        print(f"Có {count} cạnh giữa đỉnh {u} và {v}")
                    else:
                        print(f"Không có cạnh bội giữa đỉnh {u} và {v}")
                else:
                    print("Đỉnh không hợp lệ!")
            
            elif choice == '5':
                self_loops = graph.get_self_loops()
                if self_loops:
                    print(f"Các đỉnh có khuyên: {sorted(self_loops)}")
                else:
                    print("Không có khuyên trong đồ thị")
            
            else:
                print("Tùy chọn không hợp lệ!")
    
    except ValueError:
        print("Vui lòng nhập số nguyên hợp lệ!")
    except KeyboardInterrupt:
        print("\nChương trình bị ngắt bởi người dùng.")


if __name__ == "__main__":
    # Chạy demo tự động
    demonstrate_general_graph()
    
    # Chạy demo tương tác
    print("\n" + "="*50)
    interactive_demo()