from collections import deque

class SimpleGraph:
    def __init__(self, vertices):
        self.n = vertices
        self.adj = [[] for _ in range(vertices)]

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def bfs(self, s):
        visited = [False] * self.n
        distance = [-1] * self.n
        Q = deque([s])

        visited[s] = True
        distance[s] = 0

        while Q:
            u = Q.popleft()
            print(u, end=" ")

            for v in self.adj[u]:
                if not visited[v]:
                    visited[v] = True
                    distance[v] = distance[u] + 1
                    Q.append(v)
        print()
        for i in range(self.n):
            if distance[i] != -1:
                print(f"Distance to {i}: {distance[i]}")

if __name__ == "__main__":
    g = SimpleGraph(5)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    print("BFS on Simple Graph:", end=" ")
    g.bfs(0)