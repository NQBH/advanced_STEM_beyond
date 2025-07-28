import heapq
import sys

def dijkstra(adj_list, start):
    n = len(adj_list)
    
    dist = [float('inf')] * n
    parent = [-1] * n
    visited = [False] * n
    
    dist[start] = 0
    pq = [(0, start)]
    
    while pq:
        d, u = heapq.heappop(pq)
        if visited[u]:
            continue
        visited[u] = True
        
        for v, weight in adj_list[u]:
            if not visited[v]:
                new_dist = dist[u] + weight
                if new_dist < dist[v]:
                    dist[v] = new_dist
                    parent[v] = u
                    heapq.heappush(pq, (new_dist, v))
    return dist, parent

def read_graph(filename):
    """Đọc đồ thị từ file"""
    with open(filename, 'r') as f:
        n, m = map(int, f.readline().split()) 
        adj_list = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v, w = map(int, f.readline().split())
            adj_list[u].append((v, w))
            adj_list[v].append((u, w)) 
    
    return adj_list

def reconstruct_path(parent, start, end):
    """Tái tạo đường đi từ start đến end"""
    if parent[end] == -1 and start != end:
        return []
    path = []
    current = end
    while current != -1:
        path.append(current)
        current = parent[current]
    path.reverse()
    return path

def print_result(dist, parent, start):
    """In kết quả"""
    print(f"Khoảng cách ngắn nhất từ đỉnh {start}:")
    for i in range(len(dist)):
        if dist[i] == float('inf'):
            print(f"Đỉnh {i}: Không thể đến")
        else:
            path = reconstruct_path(parent, start, i)
            path_str = " → ".join(map(str, path))
            print(f"Đỉnh {i}: {dist[i]} | Đường đi: {path_str}")

if __name__ == "__main__":
    adj_list = read_graph("simple_graph.inp")
    
    start_vertex = 3
    distances, parents = dijkstra(adj_list, start_vertex)
    
    print_result(distances, parents, start_vertex)