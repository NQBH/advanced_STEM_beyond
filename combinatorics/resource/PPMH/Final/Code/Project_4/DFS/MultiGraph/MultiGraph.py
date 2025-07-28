from collections import defaultdict

class Multigraph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def dfs_util(self, v, visited):
        visited.add(v)
        print(v, end=' ')
        for neighbor in self.graph[v]:
            if neighbor not in visited:
                self.dfs_util(neighbor, visited)

    def dfs(self, start):
        visited = set()
        print("DFS traversal:")
        self.dfs_util(start, visited)

G = Multigraph()
G.add_edge(0, 1)
G.add_edge(0, 1)  # đa cạnh
G.add_edge(1, 2)
G.add_edge(2, 0)
G.add_edge(2, 3)
G.add_edge(3, 3)  # cạnh khuyên

G.dfs(2)