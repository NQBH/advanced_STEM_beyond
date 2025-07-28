class Graph:
    def __init__(self, n):
        self.n = n
        self.adj = [[0]*n for _ in range(n)]

    def add_edge(self, v, w):
        self.adj[v][w] = 1

    def del_edge(self, v, w):
        self.adj[v][w] = 0

    def edges(self):
        # Trả về danh sách tất cả các cạnh dưới dạng cặp đỉnh (v, w)
        return [(v, w) for v in range(self.n) for w in range(self.n) if self.adj[v][w] == 1]

    def incoming(self, v):
        # Trả về danh sách các cạnh đi vào đỉnh v: các cặp (u, v)
        return [(u, v) for u in range(self.n) if self.adj[u][v] == 1]

    def outgoing(self, v):
        # Trả về danh sách các cạnh đi ra từ đỉnh v: các cặp (v, w)
        return [(v, w) for w in range(self.n) if self.adj[v][w] == 1]

    def source(self, v, w):
        # Trả về đỉnh nguồn của cạnh (v, w) nếu cạnh tồn tại
        if self.adj[v][w] == 1:
            return v
        else:
            return None

    def target(self, v, w):
        # Trả về đỉnh đích của cạnh (v, w) nếu cạnh tồn tại
        if self.adj[v][w] == 1:
            return w
        else:
            return None

    def __str__(self):
        res = "Adjacency Matrix:\n"
        for row in self.adj:
            res += " ".join(map(str, row)) + "\n"
        return res


# Ví dụ sử dụng
if __name__ == "__main__":
    G = Graph(5)
    G.add_edge(0, 1)
    G.add_edge(1, 2)
    G.add_edge(2, 3)
    G.add_edge(3, 4)
    G.add_edge(4, 0)

    print(G)

    print("Edges:", G.edges())
    print("Incoming to 3:", G.incoming(3))
    print("Outgoing from 1:", G.outgoing(1))

    print("Source of edge (2, 3):", G.source(2, 3))
    print("Target of edge (2, 3):", G.target(2, 3))

    G.del_edge(2, 3)
    print("After deleting edge (2, 3):")
    print(G)
