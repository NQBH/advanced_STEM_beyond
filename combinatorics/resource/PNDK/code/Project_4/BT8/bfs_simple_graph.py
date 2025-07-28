from collections import deque

def read_graph_from_file(filename):
    with open(filename, 'r') as f:
        n, m = map(int, f.readline().split())
        adj = [[] for _ in range(n)]
        for _ in range(m):
            u, v = map(int, f.readline().split())
            adj[u].append(v)
            adj[v].append(u)  
        for i in range(n):
            adj[i].sort()
    return n, adj

def bfs(n, adj, start=0):
    visited = [False] * n
    distance = [float('inf')] * n
    parent = [None] * n
    q = deque()
    visit_order = []
    
    visited[start] = True
    distance[start] = 0
    q.append(start)
    
    while q:
        vertex = q.popleft()
        visit_order.append(vertex)
        for neighbor in adj[vertex]:
            if not visited[neighbor]:
                visited[neighbor] = True
                distance[neighbor] = distance[vertex] + 1
                parent[neighbor] = vertex
                q.append(neighbor)
    
    return visit_order, distance, parent

if __name__ == "__main__":
    filename = "simple_graph.inp"
    n, adj = read_graph_from_file(filename)
    visit_order, distance, parent = bfs(n, adj, start=0)
    
    print("Visit order:", visit_order)
    print("Distances from source:", distance)
    print("Parent array (BFS tree):", parent)