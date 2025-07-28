import heapq

# Dijkstra's algorithm for a finite multigraph (no loops, repeated edges allowed)
# Author: Nguyễn Ngọc Thạch (Python version)

def dijkstra(n, adj, src):
    dist = [float('inf')] * n
    dist[src] = 0
    pq = [(0, src)]  # priority queue as min-heap: (distance, vertex)

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in adj[u]:  # allow multiple edges between u and v
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))
    return dist

def main():
    n, m = map(int, input("Enter number of vertices and edges: ").split())
    adj = [[] for _ in range(n)]

    print("Enter edges (u v w) for each edge (0-indexed vertices, no loops):")
    for _ in range(m):
        u, v, w = map(int, input().split())
        if u == v:
            print(f"Loops are not allowed in a multigraph. Skipping edge ({u}, {v}).")
            continue
        adj[u].append((v, w))
        adj[v].append((u, w))  # undirected multigraph

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
