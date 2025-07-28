from collections import defaultdict, deque
from abc import ABC, abstractmethod
import sys

class Graph(ABC):
    """Lớp cơ sở trừu tượng cho đồ thị"""
    
    def __init__(self, vertices):
        self.vertices = vertices
        
    @abstractmethod
    def add_edge(self, u, v):
        """Thêm cạnh vào đồ thị"""
        pass
    
    @abstractmethod
    def dfs_recursive(self, start):
        """DFS đệ quy"""
        pass
    
    @abstractmethod
    def dfs_iterative(self, start):
        """DFS lặp"""
        pass
    
    @abstractmethod
    def display_graph(self):
        """Hiển thị cấu trúc đồ thị"""
        pass
    
    @abstractmethod
    def get_type(self):
        """Trả về loại đồ thị"""
        pass

class SimpleGraph(Graph):
    """Bài toán 11: Simple Graph - Đồ thị đơn giản"""
    
    def __init__(self, vertices):
        super().__init__(vertices)
        self.adj_list = [[] for _ in range(vertices)]
        
    def add_edge(self, u, v):
        """Thêm cạnh (không trùng lặp, không tự khuyên)"""
        if u != v:  # Không cho phép tự khuyên
            # Kiểm tra cạnh đã tồn tại chưa
            if v not in self.adj_list[u]:
                self.adj_list[u].append(v)
                self.adj_list[v].append(u)  # Đồ thị vô hướng
                
    def _dfs_recursive_helper(self, vertex, visited):
        """Hàm hỗ trợ đệ quy cho DFS"""
        visited[vertex] = True
        print(vertex, end=" ")
        
        # Duyệt tất cả đỉnh kề
        for neighbor in self.adj_list[vertex]:
            if not visited[neighbor]:
                self._dfs_recursive_helper(neighbor, visited)
                
    def dfs_recursive(self, start):
        """DFS đệ quy cho Simple Graph"""
        visited = [False] * self.vertices
        print("DFS Recursive (Simple Graph): ", end="")
        self._dfs_recursive_helper(start, visited)
        print()
        
    def dfs_iterative(self, start):
        """DFS lặp cho Simple Graph"""
        visited = [False] * self.vertices
        stack = [start]
        
        print("DFS Iterative (Simple Graph): ", end="")
        
        while stack:
            vertex = stack.pop()
            
            if not visited[vertex]:
                visited[vertex] = True
                print(vertex, end=" ")
                
                # Thêm các đỉnh kề vào stack (theo thứ tự ngược)
                for neighbor in reversed(self.adj_list[vertex]):
                    if not visited[neighbor]:
                        stack.append(neighbor)
        print()
        
    def display_graph(self):
        """Hiển thị cấu trúc Simple Graph"""
        print("\n=== SIMPLE GRAPH ===")
        for i in range(self.vertices):
            print(f"Đỉnh {i}: {' '.join(map(str, self.adj_list[i]))}")
            
    def get_type(self):
        return "Simple Graph"

class Multigraph(Graph):
    """Bài toán 12: Multigraph - Đa đồ thị"""
    
    def __init__(self, vertices):
        super().__init__(vertices)
        # Sử dụng dictionary để lưu số lượng cạnh giữa các đỉnh
        self.adj_list = [defaultdict(int) for _ in range(vertices)]
        
    def add_edge(self, u, v):
        """Thêm cạnh (cho phép đa cạnh)"""
        if u != v:  # Không cho phép tự khuyên
            self.adj_list[u][v] += 1
            self.adj_list[v][u] += 1  # Đồ thị vô hướng
            
    def _dfs_recursive_helper(self, vertex, visited):
        """Hàm hỗ trợ đệ quy cho DFS"""
        visited[vertex] = True
        print(vertex, end=" ")
        
        # Duyệt tất cả đỉnh kề (bỏ qua số lượng cạnh)
        for neighbor in self.adj_list[vertex]:
            if not visited[neighbor]:
                self._dfs_recursive_helper(neighbor, visited)
                
    def dfs_recursive(self, start):
        """DFS đệ quy cho Multigraph"""
        visited = [False] * self.vertices
        print("DFS Recursive (Multigraph): ", end="")
        self._dfs_recursive_helper(start, visited)
        print()
        
    def dfs_iterative(self, start):
        """DFS lặp cho Multigraph"""
        visited = [False] * self.vertices
        stack = [start]
        
        print("DFS Iterative (Multigraph): ", end="")
        
        while stack:
            vertex = stack.pop()
            
            if not visited[vertex]:
                visited[vertex] = True
                print(vertex, end=" ")
                
                # Lấy danh sách đỉnh kề
                neighbors = list(self.adj_list[vertex].keys())
                # Sắp xếp ngược để đảm bảo thứ tự đúng trong stack
                neighbors.sort(reverse=True)
                
                for neighbor in neighbors:
                    if not visited[neighbor]:
                        stack.append(neighbor)
        print()
        
    def display_graph(self):
        """Hiển thị cấu trúc Multigraph"""
        print("\n=== MULTIGRAPH ===")
        for i in range(self.vertices):
            print(f"Đỉnh {i}: ", end="")
            for neighbor, count in self.adj_list[i].items():
                print(f"{neighbor}({count}) ", end="")
            print()
            
    def get_type(self):
        return "Multigraph"

class GeneralGraph(Graph):
    """Bài toán 13: General Graph - Đồ thị tổng quát"""
    
    def __init__(self, vertices):
        super().__init__(vertices)
        # Sử dụng dictionary để lưu số lượng cạnh (bao gồm cả tự khuyên)
        self.adj_list = [defaultdict(int) for _ in range(vertices)]
        
    def add_edge(self, u, v):
        """Thêm cạnh (cho phép đa cạnh và tự khuyên)"""
        self.adj_list[u][v] += 1
        if u != v:  # Nếu không phải tự khuyên thì thêm cạnh ngược
            self.adj_list[v][u] += 1
            
    def _dfs_recursive_helper(self, vertex, visited):
        """Hàm hỗ trợ đệ quy cho DFS"""
        visited[vertex] = True
        print(vertex, end=" ")
        
        # Duyệt tất cả đỉnh kề (bao gồm cả tự khuyên)
        for neighbor in self.adj_list[vertex]:
            if not visited[neighbor]:
                self._dfs_recursive_helper(neighbor, visited)
                
    def dfs_recursive(self, start):
        """DFS đệ quy cho General Graph"""
        visited = [False] * self.vertices
        print("DFS Recursive (General Graph): ", end="")
        self._dfs_recursive_helper(start, visited)
        print()
        
    def dfs_iterative(self, start):
        """DFS lặp cho General Graph"""
        visited = [False] * self.vertices
        stack = [start]
        
        print("DFS Iterative (General Graph): ", end="")
        
        while stack:
            vertex = stack.pop()
            
            if not visited[vertex]:
                visited[vertex] = True
                print(vertex, end=" ")
                
                # Lấy danh sách đỉnh kề
                neighbors = list(self.adj_list[vertex].keys())
                # Sắp xếp ngược để đảm bảo thứ tự đúng trong stack
                neighbors.sort(reverse=True)
                
                for neighbor in neighbors:
                    if not visited[neighbor]:
                        stack.append(neighbor)
        print()
        
    def display_graph(self):
        """Hiển thị cấu trúc General Graph"""
        print("\n=== GENERAL GRAPH ===")
        for i in range(self.vertices):
            print(f"Đỉnh {i}: ", end="")
            for neighbor, count in self.adj_list[i].items():
                if neighbor == i:
                    print(f"loop({count}) ", end="")
                else:
                    print(f"{neighbor}({count}) ", end="")
            print()
            
    def get_type(self):
        return "General Graph"

def demonstrate_graph_types():
    """Hàm demo các loại đồ thị và thuật toán DFS"""
    print("=" * 50)
    print("DEMONSTRATION OF DFS ON DIFFERENT GRAPH TYPES")
    print("=" * 50)
    print()
    
    # Tạo đồ thị mẫu với 6 đỉnh
    vertices = 6
    
    # 1. Simple Graph
    print("1. SIMPLE GRAPH DEMONSTRATION")
    print("-" * 30)
    sg = SimpleGraph(vertices)
    sg.add_edge(0, 1)
    sg.add_edge(0, 2)
    sg.add_edge(1, 3)
    sg.add_edge(2, 4)
    sg.add_edge(3, 5)
    sg.add_edge(4, 5)
    # Thử thêm cạnh trùng lặp (sẽ bị bỏ qua)
    sg.add_edge(0, 1)
    
    sg.display_graph()
    sg.dfs_recursive(0)
    sg.dfs_iterative(0)
    
    print("\n" + "-" * 50)
    
    # 2. Multigraph
    print("\n2. MULTIGRAPH DEMONSTRATION")
    print("-" * 30)
    mg = Multigraph(vertices)
    mg.add_edge(0, 1)
    mg.add_edge(0, 1)  # Đa cạnh
    mg.add_edge(0, 2)
    mg.add_edge(1, 3)
    mg.add_edge(1, 3)  # Đa cạnh
    mg.add_edge(2, 4)
    mg.add_edge(3, 5)
    mg.add_edge(4, 5)
    mg.add_edge(4, 5)  # Đa cạnh
    
    mg.display_graph()
    mg.dfs_recursive(0)
    mg.dfs_iterative(0)
    
    print("\n" + "-" * 50)
    
    # 3. General Graph
    print("\n3. GENERAL GRAPH DEMONSTRATION")
    print("-" * 30)
    gg = GeneralGraph(vertices)
    gg.add_edge(0, 1)
    gg.add_edge(0, 1)  # Đa cạnh
    gg.add_edge(0, 2)
    gg.add_edge(1, 1)  # Tự khuyên
    gg.add_edge(1, 3)
    gg.add_edge(2, 2)  # Tự khuyên
    gg.add_edge(2, 4)
    gg.add_edge(3, 5)
    gg.add_edge(4, 5)
    gg.add_edge(5, 5)  # Tự khuyên
    
    gg.display_graph()
    gg.dfs_recursive(0)
    gg.dfs_iterative(0)

def complexity_analysis():
    """Phân tích độ phức tạp của các thuật toán"""
    print("\n\n" + "=" * 50)
    print("COMPLEXITY ANALYSIS")
    print("=" * 50)
    
    print("\nĐộ phức tạp thời gian DFS:")
    print("- Simple Graph: O(V + E)")
    print("- Multigraph: O(V + E') (E' = tổng số cạnh thực tế)")
    print("- General Graph: O(V + E') (E' = tổng số cạnh + tự khuyên)")
    
    print("\nĐộ phức tạp không gian:")
    print("- Recursive: O(V) (call stack)")
    print("- Iterative: O(V) (explicit stack)")
    print("- Adjacency List: O(V + E)")
    
    print("\nĐặc điểm của từng loại đồ thị:")
    print("1. Simple Graph: Không đa cạnh, không tự khuyên")
    print("2. Multigraph: Cho phép đa cạnh, không tự khuyên")
    print("3. General Graph: Cho phép đa cạnh và tự khuyên")

def compare_implementations():
    """So sánh các cách cài đặt DFS"""
    print("\n\n" + "=" * 50)
    print("COMPARISON OF DFS IMPLEMENTATIONS")
    print("=" * 50)
    
    print("\nDFS Recursive vs Iterative:")
    print("\nRecursive DFS:")
    print("+ Ưu điểm: Code đơn giản, dễ hiểu")
    print("+ Ưu điểm: Tự nhiên với cấu trúc đệ quy của thuật toán")
    print("- Nhược điểm: Stack overflow với đồ thị lớn")
    print("- Nhược điểm: Khó kiểm soát thứ tự duyệt")
    
    print("\nIterative DFS:")
    print("+ Ưu điểm: Tránh stack overflow")
    print("+ Ưu điểm: Kiểm soát được memory usage")
    print("+ Ưu điểm: Có thể tùy chỉnh thứ tự duyệt")
    print("- Nhược điểm: Code phức tạp hơn")
    print("- Nhược điểm: Cần quản lý stack thủ công")

def theoretical_foundation():
    """Nền tảng lý thuyết của DFS"""
    print("\n\n" + "=" * 50)
    print("THEORETICAL FOUNDATION")
    print("=" * 50)
    
    print("\nCông thức đệ quy cho DFS:")
    print("DFS(G, v) = {")
    print("    mark v as visited")
    print("    for each u ∈ Adj[v]:")
    print("        if u is not visited:")
    print("            DFS(G, u)")
    print("}")
    
    print("\nTính chất toán học:")
    print("1. DFS tạo ra cây DFS (DFS Tree)")
    print("2. Các cạnh được phân loại: Tree edges, Back edges")
    print("3. Thời gian khám phá và hoàn thành: discovery[v], finish[v]")
    print("4. Parenthesis theorem: [discovery[u], finish[u]] và [discovery[v], finish[v]]")
    print("   hoặc không giao nhau hoặc một chứa hoàn toàn cái kia")

def practical_applications():
    """Ứng dụng thực tế của DFS"""
    print("\n\n" + "=" * 50)
    print("PRACTICAL APPLICATIONS")
    print("=" * 50)
    
    print("\nỨng dụng của DFS:")
    print("1. Tìm đường đi trong mê cung")
    print("2. Kiểm tra tính liên thông của đồ thị")
    print("3. Tìm thành phần liên thông mạnh (SCC)")
    print("4. Sắp xếp topo (Topological Sort)")
    print("5. Phát hiện chu trình trong đồ thị")
    print("6. Giải các bài toán backtracking")
    print("7. Phân tích cấu trúc cây trong AI")

def performance_testing():
    """Test hiệu suất các thuật toán"""
    import time
    import random
    
    print("\n\n" + "=" * 50)
    print("PERFORMANCE TESTING")
    print("=" * 50)
    
    # Test với đồ thị nhỏ
    vertices = 100
    edges = 200
    
    print(f"\nTesting với {vertices} đỉnh, {edges} cạnh:")
    
    # Tạo đồ thị ngẫu nhiên
    sg = SimpleGraph(vertices)
    for _ in range(edges):
        u = random.randint(0, vertices-1)
        v = random.randint(0, vertices-1)
        sg.add_edge(u, v)
    
    # Test DFS Recursive
    start_time = time.time()
    sg.dfs_recursive(0)
    recursive_time = time.time() - start_time
    
    # Test DFS Iterative
    start_time = time.time()
    sg.dfs_iterative(0)
    iterative_time = time.time() - start_time
    
    print(f"DFS Recursive time: {recursive_time:.6f} seconds")
    print(f"DFS Iterative time: {iterative_time:.6f} seconds")
    print(f"Tỷ lệ: {recursive_time/iterative_time:.2f}")

def main():
    """Hàm chính"""
    try:
        # Tăng giới hạn đệ quy cho Python
        sys.setrecursionlimit(10000)
        
        print("DEPTH-FIRST SEARCH IMPLEMENTATION")
        print("Bài toán 11, 12, 13: DFS trên Simple Graph, Multigraph, General Graph")
        print("Author: Implementation for Graph Theory Course Project")
        
        demonstrate_graph_types()
        complexity_analysis()
        compare_implementations()
        theoretical_foundation()
        practical_applications()
        performance_testing()
        
        print("\n" + "=" * 50)
        print("Chương trình hoàn thành!")
        print("=" * 50)
        
    except Exception as e:
        print(f"Lỗi: {e}")
        import traceback
        traceback.print_exc()

if __name__ == "__main__":
    main()