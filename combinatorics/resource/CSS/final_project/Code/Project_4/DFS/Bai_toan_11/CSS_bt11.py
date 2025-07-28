class SimpleGraph:
    def __init__(self, vertices):
        self.n = vertices
        self.adj = [[] for _ in range(vertices)]

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def dfs_util(self, v, visited):
        visited[v] = True
        print(v, end=" ")

        for u in self.adj[v]:
            if not visited[u]:
                self.dfs_util(u, visited)

    def dfs(self, s):
        visited = [False] * self.n
        self.dfs_util(s, visited)
        print()

if __name__ == "__main__":
    g = SimpleGraph(5)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    print("DFS on Simple Graph:", end=" ")
    g.dfs(0)