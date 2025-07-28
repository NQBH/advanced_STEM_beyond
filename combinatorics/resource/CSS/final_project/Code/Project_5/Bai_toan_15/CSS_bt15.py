from heapq import heappush, heappop

class MultiGraph:
    def __init__(self, vertices):
        self.n = vertices
        self.adj = [[] for _ in range(vertices)]

    def add_edge(self, u, v, weight, edge_id):
        self.adj[u].append((v, weight, edge_id))
        self.adj[v].append((u, weight, edge_id))

    def dijkstra(self, s):
        dist = [float('inf')] * self.n
        Q = [(0, s)]
        dist[s] = 0

        while Q:
            d, u = heappop(Q)
            if d > dist[u]:
                continue

            for v, w, _ in self.adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    heappush(Q, (dist[v], v))

        print(f"Dijkstra on Multigraph from vertex {s}:")
        for i in range(self.n):
            print(f"Distance to {i}: {dist[i] if dist[i] != float('inf') else 'unreachable'}")

if __name__ == "__main__":
    g = MultiGraph(5)
    g.add_edge(0, 1, 4, 1)
    g.add_edge(0, 1, 2, 2)
    g.add_edge(0, 2, 8, 3)
    g.add_edge(1, 3, 5, 4)
    g.add_edge(1, 4, 9, 5)
    g.dijkstra(0)