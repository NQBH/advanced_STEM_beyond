class Graph:
    def __init__(self, n):
        # n: so dinh
        # adj: danh sach ke
        self.n = n
        self.adj = [[] for _ in range(n)]

    def add_edge(self, u, v):
        # Them canh (u,v)
        self.adj[u].append(v)
        self.adj[v].append(u)

    def generate_complete(self):
        # Sinh do thi day du K_n
        for i in range(self.n):
            for j in range(i + 1, self.n):
                self.add_edge(i, j)

    def generate_bipartite(self, p, q):
        # Sinh do thi luong phan day du K_{p,q}
        for i in range(p):
            for j in range(p, p + q):
                self.add_edge(i, j)

# Vi du su dung
if __name__ == "__main__":
    g = Graph(4)
    g.generate_complete()
    print("Complete graph edges:", 
          [(u, v) for u in range(g.n) 
                   for v in g.adj[u] if u < v])
    g = Graph(5)
    g.generate_bipartite(2, 3)
    print("Bipartite graph edges:", 
          [(u, v) for u in range(g.n) 
                   for v in g.adj[u] if u < v])