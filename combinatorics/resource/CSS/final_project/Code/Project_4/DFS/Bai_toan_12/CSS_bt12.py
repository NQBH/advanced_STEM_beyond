class MultiGraph:
    def __init__(self, vertices):
        self.n = vertices
        self.adj = [[] for _ in range(vertices)]

    def add_edge(self, u, v, edge_id):
        self.adj[u].append((v, edge_id))
        self.adj[v].append((u, edge_id))

    def dfs_util(self, v, visited):
        visited[v] = True
        print(v, end=" ")

        for u, _ in self.adj[v]:
            if not visited[u]:
                self.dfs_util(u, visited)

    def dfs(self, s):
        visited = [False] * self.n
        self.dfs_util(s, visited)
        print()

if __name__ == "__main__":
    g = MultiGraph(5)
    g.add_edge(0, 1, 1)
    g.add_edge(0, 1, 2)
    g.add_edge(0, 2, 3)
    g.add_edge(1, 3, 4)
    g.add_edge(1, 4, 5)
    print("DFS on Multigraph:", end=" ")
    g.dfs(0)