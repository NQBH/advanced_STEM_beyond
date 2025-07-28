import time
from collections import deque
from typing import List, Dict, Set, Tuple, Optional
import heapq

# =================================
# SIMPLE GRAPH (Bài toán 8)
# =================================

class SimpleGraph:
    """
    Simple Graph: Không có self-loops, không có multiple edges
    """
    
    def __init__(self, vertices: int):
        self.vertices = vertices
        self.adj_list: List[List[int]] = [[] for _ in range(vertices)]
    
    def add_edge(self, u: int, v: int):
        """Thêm cạnh vào simple graph"""
        if (0 <= u < self.vertices and 0 <= v < self.vertices and u != v):
            # Kiểm tra không có cạnh trùng lặp
            if v not in self.adj_list[u]:
                self.adj_list[u].append(v)
                self.adj_list[v].append(u)  # Đồ thị vô hướng
    
    def bfs(self, start_vertex: int) -> List[int]:
        """BFS trên Simple Graph"""
        print("=== BFS trên Simple Graph ===")
        print("Đặc điểm: Không có self-loops, không có multiple edges")
        
        start_time = time.time()
        
        if not (0 <= start_vertex < self.vertices):
            print("Đỉnh bắt đầu không hợp lệ!")
            return []
        
        result = []
        visited = [False] * self.vertices
        bfs_queue = deque([start_vertex])
        visited[start_vertex] = True
        
        print(f"Bắt đầu BFS từ đỉnh {start_vertex}")
        print("Thứ tự duyệt: ", end="")
        
        while bfs_queue:
            current_vertex = bfs_queue.popleft()
            result.append(current_vertex)
            print(current_vertex, end=" ")
            
            # Duyệt tất cả đỉnh kề
            for neighbor in self.adj_list[current_vertex]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    bfs_queue.append(neighbor)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000  # microseconds
        
        print()
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print(f"Số đỉnh đã thăm: {len(result)}/{self.vertices}")
        
        return result
    
    def display_graph(self):
        """Hiển thị đồ thị"""
        print("Simple Graph - Adjacency List:")
        for i in range(self.vertices):
            print(f"{i}: {' '.join(map(str, self.adj_list[i]))}")
    
    def get_distances(self, start_vertex: int) -> List[int]:
        """Tính khoảng cách từ đỉnh bắt đầu"""
        distances = [-1] * self.vertices
        visited = [False] * self.vertices
        bfs_queue = deque([start_vertex])
        
        visited[start_vertex] = True
        distances[start_vertex] = 0
        
        while bfs_queue:
            current_vertex = bfs_queue.popleft()
            
            for neighbor in self.adj_list[current_vertex]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    distances[neighbor] = distances[current_vertex] + 1
                    bfs_queue.append(neighbor)
        
        return distances

# =================================
# MULTIGRAPH (Bài toán 9)
# =================================

class MultiGraph:
    """
    MultiGraph: Có thể có multiple edges và self-loops
    """
    
    def __init__(self, vertices: int):
        self.vertices = vertices
        self.adj_list: List[List[Tuple[int, int]]] = [[] for _ in range(vertices)]
        self.edge_counter = 0
    
    def add_edge(self, u: int, v: int):
        """Thêm cạnh vào multigraph"""
        if 0 <= u < self.vertices and 0 <= v < self.vertices:
            self.edge_counter += 1
            self.adj_list[u].append((v, self.edge_counter))
            if u != v:  # Không tự động thêm cho self-loop
                self.adj_list[v].append((u, self.edge_counter))
    
    def bfs(self, start_vertex: int) -> List[int]:
        """BFS trên MultiGraph"""
        print("\n=== BFS trên MultiGraph ===")
        print("Đặc điểm: Có thể có multiple edges, self-loops")
        
        start_time = time.time()
        
        if not (0 <= start_vertex < self.vertices):
            print("Đỉnh bắt đầu không hợp lệ!")
            return []
        
        result = []
        visited = [False] * self.vertices
        bfs_queue = deque([start_vertex])
        visited[start_vertex] = True
        
        print(f"Bắt đầu BFS từ đỉnh {start_vertex}")
        print("Thứ tự duyệt: ", end="")
        
        while bfs_queue:
            current_vertex = bfs_queue.popleft()
            result.append(current_vertex)
            print(current_vertex, end=" ")
            
            # Duyệt tất cả cạnh từ đỉnh hiện tại
            visited_neighbors = set()  # Tránh thăm cùng một đỉnh nhiều lần trong một iteration
            
            for neighbor, edge_id in self.adj_list[current_vertex]:
                if not visited[neighbor] and neighbor not in visited_neighbors:
                    visited[neighbor] = True
                    visited_neighbors.add(neighbor)
                    bfs_queue.append(neighbor)
        
        end_time = time.time()
        execution_time = (end_time - start_time) * 1000000
        
        print()
        print(f"Thời gian thực thi: {execution_time:.0f} microseconds")
        print(f"Số đỉnh đã thăm: {len(result)}/{self.vertices}")
        
        return result
    
    def display_graph(self):
        """Hiển thị multigraph"""
        print("MultiGraph - Adjacency List with Edge IDs:")
        for i in range(self.vertices):
            edges_str = " ".join([f"({neighbor},e{edge_id})" for neighbor, edge_id in self.adj_list[i]])
            print(f"{i}: {edges_str}")
    
    def count_edges(self) -> int:
        """Đếm số cạnh"""
        return self.edge_counter

# =================================
# GENERAL GRAPH (Bài toán 10)
# =================================

class GeneralGraph:
    """
    General Graph: Linh hoạt nhất, có thể directed/undirected, weighted/unweighted
    """
    
    def __init__(self, vertices: int, directed: bool = False, 
                 allow_self_loops: bool = True, allow_multiple_edges: bool = True):
        self.vertices = vertices
        self.adj_list: List[List[Tuple[int, float]]] = [[] for _ in range(vertices)]
        self.is_directed = directed
        self.allow_self_loops = allow_self_loops
        self.allow_multiple_edges = allow_multiple_edges
    
    def add_edge(self, u: int, v: int, weight: float = 1.0):
        """Thêm cạnh vào general graph"""
        if not (0 <= u < self.vertices and 0 <= v < self.vertices):
            return
        
        # Kiểm tra self-loop
        if u == v and not self.allow_self_loops:
            print("Self-loop không được phép!")
            return
        
        # Kiểm tra multiple edges
        if not self.allow_multiple_edges:
            for neighbor, _ in self.adj_list[u]:
                if neighbor == v:
                    print("Multiple edge không được phép!")
                    return
        
        self.adj_list[u].append((v, weight))
        
        if not self.is_directed and u != v:
            self.adj_list[v].append((u, weight))
    
    def bfs(self, start_vertex: int) -> List[int]:
        """BFS trên General Graph"""
        print("\n=== BFS trên General Graph ===")
        print("Đặc điểm: ", end="")
        print(f"{'Có hướng' if self.is_directed else 'Vô hướng'}, ", end="")
        print(f"{'Cho phép self-loops' if self.allow_self_loops else 'Không cho phép self-loops'}, ", end="")
        print(f"{'Cho phép multiple edges' if self.allow_multiple_edges else 'Không cho phép multiple edges'}")
        
        start_time = time.time()
        
        if not (0 <= start_vertex < self.vertices):
            print("Đỉnh bắt đầu không hợp lệ!")
            return []
        
        result = []
        visited = [False] * self.vertices
        bfs_queue = deque([start_vertex])
        visited[start_vertex] = True
        
        print(f"Bắt đầu BFS từ đỉnh {start_vertex}")
        print("Thứ tự duyệt: ", end="")
        
        while bfs_queue:
            current_vertex = bfs_queue.popleft()
            result.append(current_vertex)
            print(current_vertex, end=" ")
            
            # Duyệt tất cả cạnh từ đỉnh hiện tại
            processed_neighbors = set()
            
            for neighbor, weight in self.adj_list[current_vertex]:
                if not visited[neighbor] and neighbor