import heapq

def dijkstra(n, adj, src):
    dist = [float('inf')] * n
    dist[src] = 0
    pq = [(0, src)]

    while pq:
        du, u = heapq.heappop(pq)
        for v, w in adj[u]:
            if dist[v] > du + w:
                dist[v] = du + w
                heapq.heappush(pq, (dist[v], v))

    for i in range(n):
        print(f"Khoảng cách từ {src} đến {i}: {dist[i]}")

n = 5
adj = [[] for _ in range(n)]
adj[0].append((1, 2))
adj[0].append((2, 4))
adj[1].append((2, 1))
adj[1].append((3, 7))
adj[2].append((4, 3))
adj[3].append((4, 1))

dijkstra(n, adj, 0)
