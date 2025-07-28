from collections import defaultdict, Counter
from typing import List, Dict, Set, Tuple
import sys

class MultigraphDFS:
    """DFS cho đa đồ thị"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]  # Danh sách kề với cạnh bội
        self.edge_count = defaultdict(int)  # Đếm số cạnh giữa mỗi cặp đỉnh
        self.reset_arrays()
    
    def reset_arrays(self):
        self.visited = [False] * self.num_vertices
        self.start_time = [0] * self.num_vertices
        self.finish_time = [0] * self.num_vertices
        self.parent = [-1] * self.num_vertices
        self.dfs_order = []
        self.time_counter = 0
        self.edge_info = []  # (u, v, count, type)
    
    def add_edge(self, u: int, v: int):
        """Thêm cạnh vào đa đồ thị"""
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)
        
        # Cập nhật số lượng cạnh
        edge = tuple(sorted([u, v]))
        self.edge_count[edge] += 1
    
    def dfs_recursive(self, u: int):
        """DFS đệ quy cho đa đồ thị"""
        self.visited[u] = True
        self.time_counter += 1
        self.start_time[u] = self.time_counter
        self.dfs_order.append(u)
        
        print(f"Thăm đỉnh {u} (start: {self.start_time[u]})")
        
        # Duyệt các đỉnh kề duy nhất
        unique_neighbors = list(set(self.adj_list[u]))
        unique_neighbors.sort()
        
        for v in unique_neighbors:
            # Đếm số cạnh giữa u và v
            edge = tuple(sorted([u, v]))
            count = self.edge_count[edge]
            
            if not self.visited[v]:
                self.parent[v] = u
                self.edge_info.append((u, v, count, "TREE"))
                print(f"  Cạnh cây: {u} -> {v} (số cạnh: {count})")
                self.dfs_recursive(v)
            else:
                # Phân loại cạnh bội
                if (self.start_time[v] < self.start_time[u] and 
                    self.finish_time[v] == 0):
                    self.edge_info.append((u, v, count, "BACK"))
                    print(f"  Cạnh ngược: {u} -> {v} (số cạnh: {count}, chu trình!)")
                elif self.start_time[v] > self.start_time[u]:
                    self.edge_info.append((u, v, count, "FORWARD"))
                    print(f"  Cạnh xuôi: {u} -> {v} (số cạnh: {count})")
                elif v != self.parent[u]:  # Tránh cạnh cha-con
                    self.edge_info.append((u, v, count, "CROSS"))
                    print(f"  Cạnh chéo: {u} -> {v} (số cạnh: {count})")
        
        self.time_counter += 1
        self.finish_time[u] = self.time_counter
        print(f"Kết thúc đỉnh {u} (finish: {self.finish_time[u]})")
    
    def dfs_complete(self):
        """DFS toàn bộ đa đồ thị"""
        self.reset_arrays()
        
        print("DFS toàn bộ đa đồ thị:")
        component_count = 0
        
        for i in range(self.num_vertices):
            if not self.visited[i]:
                component_count += 1
                print(f"\nThành phần liên thông {component_count}:")
                self.dfs_recursive(i)
        
        print(f"\nTổng số thành phần liên thông: {component_count}")
        self.analyze_multiple_edges()
    
    def analyze_multiple_edges(self):
        """Phân tích cạnh bội"""
        print("\nPhân tích cạnh bội:")
        
        has_cycle = False
        total_edges = 0
        multiple_edges = 0
        
        for u, v, count, edge_type in self.edge_info:
            print(f"Cạnh ({u},{v}): {edge_type}, Số lượng: {count}")
            
            total_edges += count
            if count > 1:
                multiple_edges += 1
            
            if edge_type == "BACK":
                has_cycle = True
        
        print(f"\nThống kê:")
        print(f"Tổng số cạnh: {total_edges // 2}")  # Chia 2 vì đồ thị vô hướng
        print(f"Số cặp đỉnh có cạnh bội: {multiple_edges}")
        print(f"Đồ thị có chu trình: {'Có' if has_cycle else 'Không'}")
    
    def print_multigraph(self):
        """In biểu diễn đa đồ thị"""
        print("Biểu diễn đa đồ thị:")
        for i in range(self.num_vertices):
            neighbors = ' '.join(map(str, self.adj_list[i]))
            print(f"{i}: {neighbors}")
        
        print("\nSố lượng cạnh giữa các cặp đỉnh:")
        for edge, count in sorted(self.edge_count.items()):
            print(f"({edge[0]},{edge[1]}): {count} cạnh")
        print()
    
    def find_path_with_min_multiple_edges(self, start: int, end: int):
        """Tìm đường đi với ít cạnh bội nhất"""
        dist = [float('inf')] * self.num_vertices
        parent = [-1] * self.num_vertices
        visited = [False] * self.num_vertices
        
        dist[start] = 0
        
        for _ in range(self.num_vertices - 1):
            u = -1
            for v in range(self.num_vertices):
                if not visited[v] and (u == -1 or dist[v] < dist[u]):
                    u = v
            
            if dist[u] == float('inf'):
                break
            
            visited[u] = True
            
            unique_neighbors = list(set(self.adj_list[u]))
            for v in unique_neighbors:
                edge = tuple(sorted([u, v]))
                edge_weight = self.edge_count[edge]  # Trọng số = số cạnh bội
                
                if dist[u] + edge_weight < dist[v]:
                    dist[v] = dist[u] + edge_weight
                    parent[v] = u
        
        if dist[end] == float('inf'):
            print(f"Không có đường đi từ {start} đến {end}")
        else:
            print(f"Đường đi với ít cạnh bội nhất từ {start} đến {end}:")
            path = []
            current = end
            while current != -1:
                path.append(current)
                current = parent[current]
            
            path.reverse()
            
            path_str = ' -> '.join(map(str, path))
            print(f"Đường đi: {path_str}")
            print(f"Tổng trọng số cạnh bội: {int(dist[end])}")
    
    def print_times(self):
        """In thông tin thời gian DFS"""
        print("\nThông tin thời gian DFS:")
        print(f"{'Đỉnh':>6} {'Start':>12} {'Finish':>12} {'Cha':>10}")
        print("-" * 40)
        
        for i in range(self.num_vertices):
            print(f"{i:>6} {self.start_time[i]:>12} {self.finish_time[i]:>12} {self.parent[i]:>10}")
        print()

# Demo cho đa đồ thị
def demonstrate_multigraph_dfs():
    print("=== DEMO DFS CHO ĐA ĐỒ THỊ ===\n")
    
    graph = MultigraphDFS(5)
    
    # Tạo đa đồ thị với cạnh bội
    print("Tạo đa đồ thị với cạnh bội:")
    graph.add_edge(0, 1)
    graph.add_edge(0, 1)  # Cạnh bội
    graph.add_edge(0, 1)  # Cạnh bội thứ 3
    graph.add_edge(0, 2)
    graph.add_edge(1, 3)
    graph.add_edge(1, 3)  # Cạnh bội
    graph.add_edge(2, 4)
    graph.add_edge(3, 4)
    graph.add_edge(3, 4)  # Cạnh bội
    graph.add_edge(1, 2)  # Tạo chu trình
    print()
    
    graph.print_multigraph()
    
    # DFS trên đa đồ thị
    graph.dfs_complete()
    graph.print_times()
    
    # Tìm đường đi với ít cạnh bội nhất
    print()
    graph.find_path_with_min_multiple_edges(0, 4)

if __name__ == "__main__":
    demonstrate_multigraph_dfs()