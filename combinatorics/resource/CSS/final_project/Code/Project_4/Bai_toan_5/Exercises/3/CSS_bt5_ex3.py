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

    def generate_path(self):
        # Sinh do thi duong Pn
        for i in range(self.n - 1):
            self.add_edge(i, i + 1)

    def generate_circle(self):
        # Sinh do thi vong Cn
        self.generate_path()
        if self.n > 2:
            self.add_edge(0, self.n - 1)

    def generate_wheel(self):
        # Sinh do thi banh xe Wn
        self.generate_circle()
        center = self.n - 1
        for i in range(self.n - 1):
            self.add_edge(center, i)

# Vi du su dung
if __name__ == "__main__":
    g = Graph(5)
    g.generate_path()
    print("Path graph edges:", [(u, v) for u in range(g.n)
                                for v in g.adj[u] if u < v])
    g = Graph(5)
    g.generate_circle()
    print("Circle graph edges:", [(u, v) for u in range(g.n)
                                  for v in g.adj[u] if u < v])
    g = Graph(5)
    g.generate_wheel()
    print("Wheel graph edges:", [(u, v) for u in range(g.n)
                                 for v in g.adj[u] if u < v])