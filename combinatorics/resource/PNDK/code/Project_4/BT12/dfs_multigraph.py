import queue
from collections import deque

def read_multigraph(filename):
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

def dfs_multigraph(n, adj, start):
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
    n, adj = read_multigraph("multigraph.inp")
    dfs_multigraph(n, adj, 0)
