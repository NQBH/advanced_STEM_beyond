from collections import defaultdict
from typing import List, Tuple, Dict, Set
import sys

class SimpleDFS:
    """DFS cho đồ thị đơn"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_list = defaultdict(list)
        self.reset_arrays()
    
    def reset_arrays(self):
        self.visited = [False] * self.num_vertices
        self.start_time = [0] * self.num_vertices
        self.finish_time = [0] * self.num_vertices
        self.parent = [-1] * self.num_vertices
        self.dfs_order = []
        self.time_counter = 0
        self.edges = []  # (u, v, type)
    
    def add_edge(self, u: int, v: int):
        """Thêm cạnh vào đồ thị vô hướng"""
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)
    
    def dfs_recursive(self, u: int):
        """DFS đệ quy"""
        self.visited[u] = True
        self.time_counter += 1
        self.start_time[u] = self.time_counter
        self.dfs_order.append(u)
        
        print(f"Thăm đỉnh {u} (start: {self.start_time[u]})")
        
        # Duyệt các đỉnh kề
        for v in sorted(self.adj_list[u]):
            if not self.visited[v]:
                self.parent[v] = u
                self.edges.append((u, v, "TREE"))
                print(f"  Cạnh cây: {u} -> {v}")
                self.dfs_recursive(v)
            else:
                # Phân loại cạnh
                if (self.start_time[v] < self.start_time[u] and 
                    self.finish_time[v] == 0):
                    self.edges.append((u, v, "BACK"))
                    print(f"  Cạnh ngược: {u} -> {v} (chu trình!)")
                elif self.start_time[v] > self.start_time[u]:
                    self.edges.append((u, v, "FORWARD"))
                    print(f"  Cạnh xuôi: {u} -> {v}")
                else:
                    self.edges.append((u, v, "CROSS"))
                    print(f"  Cạnh chéo: {u} -> {v}")
        
        self.time_counter += 1
        self.finish_time[u] = self.time_counter
        print(f"Kết thúc đỉnh {u} (finish: {self.finish_time[u]})")
    
    def dfs_iterative(self, start: int):
        """DFS không đệ quy sử dụng stack"""
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
                
                # Thêm các đỉnh kề vào stack (thứ tự ngược lại)
                neighbors = sorted(self.adj_list[u], reverse=True)
                for v in neighbors:
                    if not self.visited[v]:
                        stack.append(v)
                        if self.parent[v] == -1:
                            self.parent[v] = u
        print()
    
    def dfs_complete(self):
        """DFS toàn bộ đồ thị"""
        self.reset_arrays()
        
        print("DFS toàn bộ đồ thị:")
        component_count = 0
        
        for i in range(self.num_vertices):
            if not self.visited[i]:
                component_count += 1
                print(f"\nThành phần liên thông {component_count}:")
                self.dfs_recursive(i)
        
        print(f"\nTổng số thành phần liên thông: {component_count}")
        self.analyze_cycles()
    
    def analyze_cycles(self):
        """Phân tích chu trình"""
        has_cycle = False
        
        print("\nPhân tích cạnh:")
        for u, v, edge_type in self.edges:
            print(f"Cạnh ({u},{v}): {edge_type}")
            if edge_type == "BACK":
                has_cycle = True
        
        print(f"\nĐồ thị có chu trình: {'Có' if has_cycle else 'Không'}")
    
    def find_all_paths(self, start: int, end: int) -> List[List[int]]:
        """Tìm tất cả đường đi từ start đến end"""
        all_paths = []
        current_path = []
        temp_visited = [False] * self.num_vertices
        
        self._find_all_paths_helper(start, end, current_path, all_paths, temp_visited)
        
        print(f"\nTất cả đường đi từ {start} đến {end}:")
        for i, path in enumerate(all_paths, 1):
            path_str = ' -> '.join(map(str, path))
            print(f"Đường {i}: {path_str}")
        
        if not all_paths:
            print(f"Không có đường đi từ {start} đến {end}")
        
        return all_paths
    
    def _find_all_paths_helper(self, current: int, end: int, path: List[int], 
                              all_paths: List[List[int]], temp_visited: List[bool]):
        """Helper function for finding all paths"""
        path.append(current)
        temp_visited[current] = True
        
        if current == end:
            all_paths.append(path.copy())
        else:
            for neighbor in self.adj_list[current]:
                if not temp_visited[neighbor]:
                    self._find_all_paths_helper(neighbor, end, path, all_paths, temp_visited)
        
        path.pop()
        temp_visited[current] = False
    
    def topological_sort(self) -> List[int]:
        """Sắp xếp topo (chỉ cho đồ thị có hướng)"""
        self.reset_arrays()
        topo_stack = []
        
        # Gọi DFS cho tất cả đỉnh
        for i in range(self.num_vertices):
            if not self.visited[i]:
                self._topo_dfs(i, topo_stack)
        
        return topo_stack[::-1]
    
    def _topo_dfs(self, u: int, topo_stack: List[int]):
        """DFS helper for topological sort"""
        self.visited[u] = True
        
        for v in self.adj_list[u]:
            if not self.visited[v]:
                self._topo_dfs(v, topo_stack)
        
        topo_stack.append(u)
    
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
    
    def print_graph(self):
        """In biểu diễn đồ thị"""
        print("Biểu diễn đồ thị đơn:")
        for i in range(self.num_vertices):
            neighbors = ' '.join(map(str, sorted(self.adj_list[i])))
            print(f"{i}: {neighbors}")
        print()
    
    def is_connected(self) -> bool:
        """Kiểm tra tính liên thông"""
        self.reset_arrays()
        self.dfs_recursive(0)
        
        return all(self.visited)

# Demo cho đồ thị đơn
def demonstrate_simple_dfs():
    print("=== DEMO DFS CHO ĐỒ THỊ ĐƠN ===\n")
    
    graph = SimpleDFS(6)
    
    # Tạo đồ thị mẫu
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 3)
    graph.add_edge(2, 4)
    graph.add_edge(3, 5)
    graph.add_edge(4, 5)
    graph.add_edge(1, 2)  # Tạo chu trình
    
    graph.print_graph()
    
    # DFS đệ quy
    print("1. DFS ĐỆ QUY:")
    graph.dfs_complete()
    graph.print_times()
    graph.print_dfs_tree()
    
    # DFS không đệ quy
    print("2. DFS KHÔNG ĐỆ QUY:")
    graph.dfs_iterative(0)
    
    # Tìm tất cả đường đi
    graph.find_all_paths(0, 5)
    
    # Kiểm tra liên thông
    print(f"\nĐồ thị có liên thông: {'Có' if graph.is_connected() else 'Không'}")

if __name__ == "__main__":
    demonstrate_simple_dfs()