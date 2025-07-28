from collections import defaultdict

class Graph:
    def __init__(self):
        self.adj = defaultdict(list)

    def add_edge(self, u, v):
        self.adj[u].append(v)
        # Nếu là đồ thị vô hướng, thêm cạnh ngược:
        # self.adj[v].append(u)

    def dfs_util(self, v, visited):
        visited.add(v)
        print(v, end=' ')
        for neighbor in self.adj[v]:
            if neighbor not in visited:
                self.dfs_util(neighbor, visited)

    def dfs(self):
        visited = set()
        for vertex in self.adj:
            if vertex not in visited:
                self.dfs_util(vertex, visited)

g = Graph()
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)

print("DFS của đồ thị:")
g.dfs()