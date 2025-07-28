import heapq
import sys

def dijkstra_multigraph(adj_list, start):
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
            if u == v:
                continue
                
            if not visited[v]:
                new_dist = dist[u] + weight
                if new_dist < dist[v]:
                    dist[v] = new_dist
                    parent[v] = u
                    heapq.heappush(pq, (new_dist, v))
    
    return dist, parent

def read_multigraph(filename):
    with open(filename, 'r') as f:
        n, m = map(int, f.readline().split()) 
        
        adj_list = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v, w = map(int, f.readline().split())
            adj_list[u].append((v, w))
            adj_list[v].append((u, w)) 
    
    return adj_list


def reconstruct_path(parent, start, end):
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
    print("=" * 50)
    print(f"KHOẢNG CÁCH NGẮN NHẤT TỪ ĐỈNH {start} (MULTIGRAPH)")
    print("=" * 50)
    
    for i in range(len(dist)):
        if dist[i] == float('inf'):
            print(f"Đỉnh {i}: ∞ | Không thể đến")
        else:
            path = reconstruct_path(parent, start, i)
            path_str = " → ".join(map(str, path))
            print(f"Đỉnh {i}: {dist[i]} | Đường đi: {path_str}")
    
    print("=" * 50)

if __name__ == "__main__":
        adj_list = read_multigraph("multigraph.inp")
        
        start_vertex = 0
        distances, parents = dijkstra_multigraph(adj_list, start_vertex)
        
        print_result(distances, parents, start_vertex)