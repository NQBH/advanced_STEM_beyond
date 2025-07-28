import heapq

# Dijkstra's algorithm for a general graph (repeated edges and loops allowed)
# Author: Nguyễn Ngọc Thạch
# This program finds the shortest path from a source vertex to all other vertices
# in a weighted general graph with non-negative edge weights.

# Dijkstra's algorithm for general graph
# n: number of vertices (0-indexed)
# adj: adjacency list where adj[u] = list of pairs (v, w) for each edge u-v with weight w
#      (multiple edges and loops allowed)
# src: source vertex
def dijkstra(n, adj, src):
    dist = [float('inf')] * n
    dist[src] = 0
    pq = [(0, src)]  # priority queue as min-heap: (distance, vertex)

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            # For general graph: process all edges, including loops (u == v) and repeated edges
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    return dist

def main():
    n, m = map(int, input("Enter number of vertices and edges: ").split())
    adj = [[] for _ in range(n)]
    print("Enter edges (u v w) for each edge (0-indexed vertices, loops and repeated edges allowed):")
    for _ in range(m):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))
        adj[v].append((u, w))  # Undirected general graph: add both directions

    src = int(input("Enter source vertex: "))
    dist = dijkstra(n, adj, src)

    print(f"Shortest distances from vertex {src}:")
    for i in range(n):
        if dist[i] == float('inf'):
            print(f"Vertex {i}: INF")
        else:
            print(f"Vertex {i}: {dist[i]}")

if __name__ == "__main__":
    main()
