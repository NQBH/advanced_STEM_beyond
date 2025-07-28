import heapq

# Dijkstra's algorithm for a finite simple graph
# Author: Nguyễn Ngọc Thạch 

# Function to perform Dijkstra's algorithm
# n: number of vertices (vertices are 0-indexed)
# adj: adjacency list where adj[u] = list of (v, w) meaning edge u-v with weight w
# src: source vertex
def dijkstra(n, adj, src):
    dist = [float('inf')] * n  # Distance from src to each vertex
    dist[src] = 0
    pq = [(0, src)]  # Min-heap priority queue

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    
    return dist

def main():
    n, m = map(int, input("Enter number of vertices and edges: ").split())
    adj = [[] for _ in range(n)]
    
    print("Enter edges (u v w) for each edge (0-indexed vertices):")
    for _ in range(m):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))
        adj[v].append((u, w))  # Since the graph is undirected
    
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
