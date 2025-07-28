# Depth-first search algorithm for a finite simple graph
# Author: Nguyễn Ngọc Thạch
# This program performs DFS traversal on a simple graph starting from a given vertex.

# Function to perform DFS using recursion
# adj: adjacency list representation of the graph
# visited: list to track visited vertices
# vertex: current vertex to visit
def dfs_recursive(adj, visited, vertex):
    visited[vertex] = True
    print(vertex, end=" ")  # Print the current vertex

    # Visit all adjacent vertices
    for neighbor in adj[vertex]:
        if not visited[neighbor]:
            dfs_recursive(adj, visited, neighbor)

# Function to perform DFS using stack (iterative approach)
# adj: adjacency list representation of the graph
# start: starting vertex for DFS
def dfs_iterative(adj, start):
    n = len(adj)
    visited = [False] * n
    s = []

    # Push starting vertex onto stack
    s.append(start)

    while s:
        vertex = s.pop()

        if not visited[vertex]:
            visited[vertex] = True
            print(vertex, end=" ")  # Print the current vertex

            # Push all unvisited neighbors onto stack
            # Note: We push in reverse order to maintain DFS order
            for neighbor in reversed(adj[vertex]):
                if not visited[neighbor]:
                    s.append(neighbor)

def main():
    n, m = map(int, input("Enter number of vertices and edges: ").split())

    adj = [[] for _ in range(n)]
    print("Enter edges (u v) for each edge (0-indexed vertices):")
    for _ in range(m):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)  # Since the graph is undirected

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
