# Depth-first search algorithm for a finite multigraph (no loops, repeated edges allowed)
# Author: Nguyễn Ngọc Thạch
# This program performs DFS traversal on a multigraph starting from a given vertex.

# Recursive DFS for multigraph
def dfs_recursive(adj, visited, vertex):
    visited[vertex] = True
    print(vertex, end=" ")
    for neighbor in adj[vertex]:
        if not visited[neighbor]:
            dfs_recursive(adj, visited, neighbor)

# Iterative DFS for multigraph
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
    print("Enter edges (u v) for each edge (0-indexed vertices, no loops):")
    for _ in range(m):
        u, v = map(int, input().split())
        if u == v:
            print(f"Loops are not allowed in a multigraph. Skipping edge ({u}, {v}).")
            continue
        adj[u].append(v)
        adj[v].append(u)  # Undirected multigraph

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
