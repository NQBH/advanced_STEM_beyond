import queue
from collections import deque

def read_general_graph_from_file(filename):
    with open(filename, 'r') as fin:
        lines = [line.strip() for line in fin if line.strip() and not line.startswith('#')]
    
    n, m = map(int, lines[0].split())
    adj = [[] for _ in range(n)]
    
    for i in range(1, m + 1):
        u, v = map(int, lines[i].split())
        adj[u].append(v)
        if u != v:  # Tránh thêm cạnh tự khép (self-loop) hai lần
            adj[v].append(u)  # Đồ thị vô hướng
    
    # Sắp xếp lại danh sách kề
    for i in range(n):
        adj[i].sort()
    
    return n, adj

def bfs(n, adj, start):
    visited = [False] * n
    distance = [-1] * n
    parent = [-1] * n
    visit_order = []
    q = queue.Queue()

    visited[start] = True
    distance[start] = 0
    q.put(start)

    while not q.empty():
        vertex = q.get()
        visit_order.append(vertex)
        for neighbor in adj[vertex]:
            if not visited[neighbor]:
                visited[neighbor] = True
                distance[neighbor] = distance[vertex] + 1
                parent[neighbor] = vertex
                q.put(neighbor)

    print("Visit order:", " ".join(map(str, visit_order)))
    print("Distances from source:", " ".join(map(str, distance)))
    print("Parent array (BFS tree):", " ".join(map(str, parent)))

    return visit_order

def main():
    filename = "general_graph.inp"
    n, adj = read_general_graph_from_file(filename)
    bfs(n, adj, 0)

if __name__ == "__main__":
    main()