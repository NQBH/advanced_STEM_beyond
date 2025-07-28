from collections import deque

class GeneralGraph:
    def __init__(self, vertices):
        self.n = vertices
        self.adj = [[] for _ in range(vertices)]

    def add_edge(self, u, v, edge_id):
        self.adj[u].append((v, edge_id))
        self.adj[v].append((u, edge_id))

    def bfs(self, s):
        visited = [False] * self.n
        distance = [-1] * self.n
        Q = deque([s])

        visited[s] = True
        distance[s] = 0

        while Q:
            u = Q.popleft()
            print(u, end=" ")

            for v, _ in self.adj[u]:
                if not visited[v] and v != u:  # Skip self-loops
                    visited[v] = True
                    distance[v] = distance[u] + 1
                    Q.append(v)
        print()
        for i in range(self.n):
            if distance[i] != -1:
                print(f"Distance to {i}: {distance[i]}")

if __name__ == "__main__":
    g = GeneralGraph(5)
    g.add_edge(0, 1, 1)
    g.add_edge(0, 1, 2)
    g.add_edge(0, 2, 3)
    g.add_edge(1, 3, 4)
    g.add_edge(1, 4, 5)
    g.add_edge(0, 0, 6)
    print("BFS on General Graph:", end=" ")
    g.bfs(0)