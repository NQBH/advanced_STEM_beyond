import queue
from collections import deque

def read_simple_graph(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()

    n, m = map(int, lines[0].split())
    adj = [[] for _ in range(n)]
    for i in range(1, m + 1):
        u, v = map(int, lines[i].split())
        adj[u].append(v)
        adj[v].append(u)  # vô hướng

    # sort để duyệt ổn định
    for neighbors in adj:
        neighbors.sort()

    return n, adj

def dfs_simple_graph(n, adj, start):
    visited = [False] * n
    parent = [-1] * n
    dfs_order = []

    def dfs(u):
        visited[u] = True
        dfs_order.append(u)
        for v in adj[u]:
            if not visited[v]:
                parent[v] = u
                dfs(v)

    dfs(start)
    print("DFS order:", dfs_order)
    print("Parent array:", parent)
    return dfs_order, parent


if __name__ == "__main__":
    n, adj = read_simple_graph("simple_graph.inp")
    dfs_simple_graph(n, adj, 0)
