from collections import deque

# Breadth-first search algorithm for a general graph (repeated edges and loops allowed)
# Author: Nguyễn Ngọc Thạch
# This program performs BFS traversal on a general graph starting from a given vertex.

# BFS function for general graph
def bfs(adj, start):
    n = len(adj)
    visited = [False] * n
    q = deque()
    visited[start] = True
    q.append(start)
    while q:
        vertex = q.popleft()
        print(vertex, end=" ")
        for neighbor in adj[vertex]:
            if not visited[neighbor]:
                visited[neighbor] = True
                q.append(neighbor)

def main():
    n, m = map(int, input("Enter number of vertices and edges: ").split())
    adj = [[] for _ in range(n)]
    print("Enter edges (u v) for each edge (0-indexed vertices, loops and repeated edges allowed):")
    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)  # Undirected general graph: add both directions, including loops

    start = int(input("Enter starting vertex: "))
    print("BFS traversal: ", end="")
    bfs(adj, start)
    print()

if __name__ == "__main__":
    main()
