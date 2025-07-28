import heapq
from typing import List, Tuple, Dict, Optional
import sys

class SimpleDijkstra:
    """Dijkstra cho đồ thị đơn"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]
        self.reset()
    
    def reset(self):
        self.dist = [float('inf')] * self.num_vertices
        self.parent = [-1] * self.num_vertices
        self.visited = [False] * self.num_vertices
    
    def add_edge(self, u: int, v: int, weight: int):
        """Thêm cạnh vào đồ thị vô hướng"""
        self.adj_list[u].append((v, weight))
        self.adj_list[v].append((u, weight))
        print(f"Thêm cạnh {u} - {v} với trọng số {weight}")
    
    def dijkstra_with_heap(self, source: int):
        """Dijkstra sử dụng heap"""
        self.reset()
        
        # Heap: (distance, vertex)
        heap = [(0, source)]
        self.dist[source] = 0
        
        print(f"\nDijkstra với heap từ đỉnh {source}:")
        
        while heap:
            current_dist, u = heapq.heappop(heap)
            
            if self.visited[u]:
                continue
                
            self.visited[u] = True
            print(f"Xử lý đỉnh {u} với khoảng cách {current_dist}")
            
            # Duyệt các đỉnh kề
            for v, weight in self.adj_list[u]:
                if not self.visited[v]:
                    new_dist = self.dist[u] + weight
                    
                    if new_dist < self.dist[v]:
                        self.dist[v] = new_dist
                        self.parent[v] = u
                        heapq.heappush(heap, (new_dist, v))
                        
                        print(f"  Cập nhật dist[{v}] = {new_dist} (qua đỉnh {u})")
    
    def dijkstra_basic(self, source: int):
        """Dijkstra cơ bản với mảng"""
        self.reset()
        
        self.dist[source] = 0
        
        print(f"\nDijkstra cơ bản từ đỉnh {source}:")
        
        for count in range(self.num_vertices):
            # Tìm đỉnh chưa xử lý có khoảng cách nhỏ nhất
            u = self._find_min_distance()
            if u == -1:
                break
                
            self.visited[u] = True
            print(f"Bước {count + 1}: Chọn đỉnh {u} với khoảng cách {self.dist[u]}")
            
            # Cập nhật khoảng cách đến các đỉnh kề
            for v, weight in self.adj_list[u]:
                if (not self.visited[v] and 
                    self.dist[u] != float('inf') and 
                    self.dist[u] + weight < self.dist[v]):
                    
                    self.dist[v] = self.dist[u] + weight
                    self.parent[v] = u
                    
                    print(f"  Cập nhật dist[{v}] = {self.dist[v]}")
    
    def _find_min_distance(self) -> int:
        """Tìm đỉnh chưa xử lý có khoảng cách nhỏ nhất"""
        min_dist = float('inf')
        min_vertex = -1
        
        for v in range(self.num_vertices):
            if not self.visited[v] and self.dist[v] < min_dist:
                min_dist = self.dist[v]
                min_vertex = v
                
        return min_vertex
    
    def print_results(self, source: int):
        """In kết quả Dijkstra"""
        print(f"\nKết quả Dijkstra từ đỉnh {source}:")
        print(f"{'Đỉnh':>6} {'Khoảng cách':>12} {'Đường đi':>15}")
        print("-" * 35)
        
        for i in range(self.num_vertices):
            print(f"{i:>6}", end="")
            
            if self.dist[i] == float('inf'):
                print(f"{'∞':>12} {'Không có':>15}")
            else:
                print(f"{self.dist[i]:>12}", end="")
                path_str = self._get_path_string(source, i)
                print(f"{path_str:>15}")
        print()
    
    def _get_path_string(self, source: int, dest: int) -> str:
        """Lấy chuỗi biểu diễn đường đi"""
        if dest == source:
            return str(dest)
        
        if self.parent[dest] == -1:
            return "Không có đường"
        
        path = []
        current = dest
        
        while current != -1:
            path.append(current)
            current = self.parent[current]
        
        path.reverse()
        return "→".join(map(str, path))
    
    def print_graph(self):
        """In đồ thị"""
        print("Đồ thị đơn có trọng số:")
        for i in range(self.num_vertices):
            print(f"Đỉnh {i}: ", end="")
            for v, weight in self.adj_list[i]:
                print(f"({v},{weight}) ", end="")
            print()
        print()
    
    def shortest_path(self, source: int, dest: int) -> Tuple[int, List[int]]:
        """Tìm đường đi ngắn nhất giữa hai đỉnh"""
        self.dijkstra_with_heap(source)
        
        if self.dist[dest] == float('inf'):
            return (-1, [])
        
        path = []
        current = dest
        
        while current != -1:
            path.append(current)
            current = self.parent[current]
        
        path.reverse()
        return (self.dist[dest], path)
    
    def analyze_graph(self):
        """Phân tích đồ thị"""
        print("Phân tích đồ thị:")
        
        # Kiểm tra tính liên thông
        self.dijkstra_with_heap(0)
        is_connected = all(dist != float('inf') for dist in self.dist)
        
        print(f"Đồ thị liên thông: {'Có' if is_connected else 'Không'}")
        
        # Tìm cặp đỉnh có khoảng cách lớn nhất
        max_dist = 0
        farthest_pair = (-1, -1)
        
        for i in range(self.num_vertices):
            self.dijkstra_with_heap(i)
            for j in range(self.num_vertices):
                if self.dist[j] != float('inf') and self.dist[j] > max_dist:
                    max_dist = self.dist[j]
                    farthest_pair = (i, j)
        
        if farthest_pair[0] != -1:
            print(f"Cặp đỉnh xa nhất: {farthest_pair[0]} và {farthest_pair[1]} "
                  f"(khoảng cách: {max_dist})")
        print()

def main():
    """Demo Dijkstra cho đồ thị đơn"""
    print("=== DIJKSTRA CHO ĐỒ THỊ ĐƠN ===\n")
    
    graph = SimpleDijkstra(5)
    
    # Tạo đồ thị mẫu
    graph.add_edge(0, 1, 4)
    graph.add_edge(0, 2, 2)
    graph.add_edge(1, 2, 1)
    graph.add_edge(1, 3, 5)
    graph.add_edge(2, 3, 8)
    graph.add_edge(2, 4, 10)
    graph.add_edge(3, 4, 2)
    
    print()
    graph.print_graph()
    
    # Dijkstra với heap
    graph.dijkstra_with_heap(0)
    graph.print_results(0)
    
    # Dijkstra cơ bản
    graph.dijkstra_basic(0)
    graph.print_results(0)
    
    # Tìm đường đi cụ thể
    dist, path = graph.shortest_path(0, 4)
    print("Đường đi ngắn nhất từ 0 đến 4:")
    print(f"Độ dài: {dist}")
    print(f"Đường đi: {'→'.join(map(str, path))}\n")
    
    # Phân tích đồ thị
    graph.analyze_graph()

if __name__ == "__main__":
    main()