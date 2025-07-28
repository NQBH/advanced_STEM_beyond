# Depth-first search algorithm for a general graph (repeated edges and loops allowed)
# Author: Nguyễn Ngọc Thạch
# This program performs DFS traversal on a general graph starting from a given vertex.

# Recursive DFS for general graph
def dfs_recursive(adj, visited, vertex):
    visited[vertex] = True
    print(vertex, end=" ")
    for neighbor in adj[vertex]:
        if not visited[neighbor]:
            dfs_recursive(adj, visited, neighbor)

# Iterative DFS for general graph
def dfs_iterative(adj, start):
    n = len(adj)
    visited = [False] * n
    s = []
    s.append(start)
    while s:
        vertex = s.pop()
        if not visited[vertex]:
            visited[vertex] = True
            print(vertex, end=" ")
            # Push neighbors in reverse to maintain DFS order
            for neighbor in reversed(adj[vertex]):
                if not visited[neighbor]:
                    s.append(neighbor)

def main():
    n, m = map(int, input("Enter number of vertices and edges: ").split())
    adj = [[] for _ in range(n)]
    print("Enter edges (u v) for each edge (0-indexed vertices, loops and repeated edges allowed):")
    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)  # Undirected general graph: add both directions, including loops

    start = int(input("Enter starting vertex: "))

    print("\nDFS using recursion: ", end="")
    visited = [False] * n
    dfs_recursive(adj, visited, start)
    print()

    print("DFS using iteration: ", end="")
    dfs_iterative(adj, start)
    print()

if __name__ == "__main__":
    main()
