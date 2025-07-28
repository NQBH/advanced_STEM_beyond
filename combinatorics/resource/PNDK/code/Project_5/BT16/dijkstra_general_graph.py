import heapq

def check_negative_weights(adj_list):
    """Kiểm tra có trọng số âm không"""
    for u in range(len(adj_list)):
        for v, weight in adj_list[u]:
            if weight < 0:
                return True, (u, v, weight)
    return False, None

def dijkstra_general(adj_list, start):
    n = len(adj_list)
    
    has_negative, edge_info = check_negative_weights(adj_list)
    if has_negative:
        u, v, w = edge_info
        print(f"Phát hiện trọng số âm tại cạnh {u}→{v} (trọng số: {w})")

        return None, None
    
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

def read_general_graph(filename):
    """Đọc general graph từ file"""
    with open(filename, 'r') as f:
        header = f.readline().strip()
        if header.startswith('#'):
            graph_type = header.split()[1]
            n, m = map(int, f.readline().split())
        else:
            graph_type = "directed"
            n, m = map(int, header.split())
        
        adj_list = [[] for _ in range(n)]
        
        for _ in range(m):
            u, v, w = map(int, f.readline().split())
            adj_list[u].append((v, w))
            
            if graph_type == "undirected":
                adj_list[v].append((u, w))
    
    return adj_list, graph_type


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

def print_result(dist, parent, start, graph_type):
    print(f"Khoảng cách ngắn nhất từ đỉnh {start} ({graph_type.upper()}):")
    
    for i in range(len(dist)):
        if dist[i] == float('inf'):
            print(f"Đỉnh {i}: ∞ | Không thể đến")
        else:
            path = reconstruct_path(parent, start, i)
            path_str = " → ".join(map(str, path))
            print(f"Đỉnh {i}: {dist[i]} | Đường đi: {path_str}")

if __name__ == "__main__":
        
        adj_list, graph_type = read_general_graph("general_graph.inp")

        #adj_list, graph_type = read_general_graph("negative_graph.inp")
                
        start_vertex = 3
        distances, parents = dijkstra_general(adj_list, start_vertex)
        
        if distances is not None:  
            print_result(distances, parents, start_vertex, graph_type)
        