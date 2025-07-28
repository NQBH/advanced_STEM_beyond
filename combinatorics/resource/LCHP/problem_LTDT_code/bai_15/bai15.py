import heapq
from typing import List, Tuple, Dict, Optional
from collections import defaultdict

class MultiEdge:
    """Lớp biểu diễn cạnh trong đa đồ thị"""
    def __init__(self, to: int, weight: int, edge_id: int):
        self.to = to
        self.weight = weight
        self.id = edge_id

class MultiGraphDijkstra:
    """Dijkstra cho đa đồ thị"""
    
    def __init__(self, num_vertices: int):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]
        self.edge_id_counter = 0
        self.reset()
    
    def reset(self):
        self.dist = [float('inf')] * self.num_vertices
        self.parent = [-1] * self.num_vertices
        self.parent_edge_id = [-1] * self.num_vertices
        self.visited = [False] * self.num_vertices
    
    def add_edge(self, u: int, v: int, weight: int):
        """Thêm cạnh vào đa đồ thị"""
        # Thêm cạnh từ u đến v
        self.adj_list[u].append(MultiEdge(v, weight, self.edge_id_counter))
        
        # Nếu không phải vòng lặp, thêm cạnh ngược lại
        if u != v:
            self.adj_list[v].append(MultiEdge(u, weight, self.edge_id_counter))
        
        print(f"Thêm cạnh {u} - {v} với trọng số {weight} (ID: {self.edge_id_counter})")
        self.edge_id_counter += 1
    
    def dijkstra_multigraph(self, source: int):
        """Dijkstra cho đa đồ thị - chọn cạnh tốt nhất"""
        self.reset()
        
        heap = [(0, source)]
        self.dist[source] = 0
        
        print(f"\nDijkstra trên đa đồ thị từ đỉnh {source}:")
        
        while heap:
            current_dist, u = heapq.heappop(heap)
            
            if self.visited[u]:
                continue
                
            self.visited[u] = True
            print(f"Xử lý đỉnh {u} với khoảng cách {current_dist}")
            
            # Nhóm các cạnh theo đỉnh đích và chọn cạnh tốt nhất
            best_edges = {}
            
            for edge in self.adj_list[u]:
                v = edge.to
                
                if not self.visited[v]:
                    # Chọn cạnh có trọng số nhỏ nhất đến đỉnh v
                    if v not in best_edges or edge.weight < best_edges[v].weight:
                        best_edges[v] = edge
            
            # Cập nhật khoảng cách với các cạnh tốt nhất
            for v, edge in best_edges.items():
                new_dist = self.dist[u] + edge.weight
                
                if new_dist < self.dist[v]:
                    self.dist[v] = new_dist
                    self.parent[v] = u
                    self.parent_edge_id[v] = edge.id
                    heapq.heappush(heap, (new_dist, v))
                    
                    print(f"  Cập nhật dist[{v}] = {new_dist} "
                          f"(qua cạnh ID {edge.id})")
    
    def dijkstra_all_edges(self, source: int):
        """Dijkstra xử lý tất cả cạnh song song"""
        self.reset()
        
        heap = [(0, source)]
        self.dist[source] = 0
        
        print(f"\nDijkstra xử lý tất cả cạnh song song từ đỉnh {source}:")
        
        while heap:
            current_dist, u = heapq.heappop(heap)
            
            if self.visited[u]:
                continue
                
            self.visited[u] = True
            print(f"Xử lý đỉnh {u} với khoảng cách {current_dist}")
            
            # Xử lý tất cả các cạnh
            for edge in self.adj_list[u]:
                v = edge.to
                weight = edge.weight
                
                if not self.visited[v]:
                    new_dist = self.dist[u] + weight
                    
                    if new_dist < self.dist[v]:
                        self.dist[v] = new_dist
                        self.parent[v] = u
                        self.parent_edge_id[v] = edge.id
                        heapq.heappush(heap, (new_dist, v))
                        
                        print(f"  Cập nhật dist[{v}] = {new_dist} "
                              f"(qua cạnh ID {edge.id} với trọng số {weight})")
    
    def print_multigraph(self):
        """In đa đồ thị"""
        print("Đa đồ thị có trọng số:")
        
        for i in range(self.num_vertices):
            print(f"Đỉnh {i}: ", end="")
            
            # Nhóm cạnh theo đỉnh đích
            edge_groups = defaultdict(list)
            for edge in self.adj_list[i]:
                edge_groups[edge.to].append(edge)
            
            for dest, edges in edge_groups.items():
                weights = [str(edge.weight) for edge in edges]
                print(f"{dest}[{','.join(weights)}] ", end="")
            
            print()
        print()
    
    def print_results(self, source: int):
        """In kết quả"""
        print(f"\nKết quả Dijkstra từ đỉnh {source}:")
        print(f"{'Đỉnh':>6} {'Khoảng cách':>12} {'Cạnh ID':>10} {'Đường đi':>15}")
        print("-" * 45)
        
        for i in range(self.num_vertices):
            print(f"{i:>6}", end="")
            
            if self.dist[i] == float('inf'):
                print(f"{'∞':>12} {'-':>10} {'Không có':>15}")
            else:
                print(f"{self.dist[i]:>12} {self.parent_edge_id[i]:>10}", end="")
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
        
        while current != -1 and current != source:
            path.append(current)
            current = self.parent[current]
        
        if current == source:
            path.append(source)
        
        path.reverse()
        return "→".join(map(str, path))
    
    def find_all_optimal_paths(self, source: int, dest: int):
        """Tìm tất cả đường đi tối ưu"""
        self.dijkstra_all_edges(source)
        
        if self.dist[dest] == float('inf'):
            print(f"Không có đường đi từ {source} đến {dest}")
            return
        
        print(f"Tất cả đường đi tối ưu từ {source} đến {dest} "
              f"(chi phí {self.dist[dest]}):")
        
        all_paths = []
        self._find_all_paths_helper(source, dest, self.dist[dest], 0, [], all_paths)
        
        for i, path in enumerate(all_paths):
            print(f"Đường {i + 1}: {'→'.join(map(str, path))}")
    
    def _find_all_paths_helper(self, current: int, dest: int, target_cost: int,
                              current_cost: int, path: List[int], 
                              all_paths: List[List[int]]):
        """Helper function để tìm tất cả đường đi"""
        path.append(current)
        
        if current == dest and current_cost == target_cost:
            all_paths.append(path[:])
            path.pop()
            return
        
        if current_cost >= target_cost:
            path.pop()
            return
        
        for edge in self.adj_list[current]:
            next_vertex = edge.to
            new_cost = current_cost + edge.weight
            
            if new_cost <= target_cost:
                self._find_all_paths_helper(next_vertex, dest, target_cost,
                                          new_cost, path, all_paths)
        
        path.pop()

def demonstrate_multigraph_dijkstra():
    """Demo Dijkstra cho đa đồ thị"""
    print("=== DEMO DIJKSTRA CHO ĐA ĐỒ THỊ ===\n")
    
    graph = MultiGraphDijkstra(4)
    
    # Tạo đa đồ thị với cạnh song song
    graph.add_edge(0, 1, 5)  # Cạnh song song 1
    graph.add_edge(0, 1, 3)  # Cạnh song song 2
    graph.add_edge(0, 2, 4)
    graph.add_edge(2, 3, 2)
    graph.add_edge(1, 3, 6)  # Cạnh song song 1
    graph.add_edge(1, 3, 1)  # Cạnh song song 2
    graph.add_edge(2, 2, 2)  # Vòng lặp
    
    print()
    graph.print_multigraph()
    
    # Dijkstra chọn cạnh tốt nhất
    graph.dijkstra_multigraph(0)
    graph.print_results(0)
    
    # Dijkstra xử lý tất cả cạnh
    graph.dijkstra_all_edges(0)
    graph.print_results(0)
    
    # Tìm tất cả đường đi tối ưu
    graph.find_all_optimal_paths(0, 3)

if __name__ == "__main__":
    demonstrate_multigraph_dijkstra()