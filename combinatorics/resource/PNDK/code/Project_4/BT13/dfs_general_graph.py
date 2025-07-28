import queue
from collections import deque

def read_general_graph(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()

    n, m = map(int, lines[0].split())
    adj = [[] for _ in range(n)]
    for i in range(1, m + 1):
        u, v = map(int, lines[i].split())
        adj[u].append(v)
        if u != v:
            adj[v].append(u)  # vô hướng

    for neighbors in adj:
        neighbors.sort()

    return n, adj

def dfs_general_graph(n, adj):
    visited = [False] * n
    parent = [-1] * n
    dfs_forest = []

    def dfs(u):
        visited[u] = True
        dfs_forest.append(u)
        for v in adj[u]:
            if not visited[v]:
                parent[v] = u
                dfs(v)

    for u in range(n):
        if not visited[u]:
            dfs(u)

    print("DFS forest order:", dfs_forest)
    print("Parent array:", parent)
    return dfs_forest, parent


if __name__ == "__main__":
    n, adj = read_general_graph("general_graph.inp")
    dfs_general_graph(n, adj)
