class Graph:
    def __init__(self, n):
        # n: so dinh cua do thi
        # adj_matrix: ma tran ke, adj_matrix[u][v] = 1 neu co canh (u,v)
        self.n = n
        self.adj_matrix = [[0] * n for _ in range(n)]

    def add_edge(self, v, w):
        # Them canh (v,w)
        self.adj_matrix[v][w] = 1
        self.adj_matrix[w][v] = 1

    def del_edge(self, v, w):
        # Xoa canh (v,w)
        self.adj_matrix[v][w] = 0
        self.adj_matrix[w][v] = 0

    def edges(self):
        # Tra ve danh sach cac cap (u,v) dai dien cho canh
        return [(u, v)
                for u in range(self.n)
                for v in range(u + 1, self.n)
                if self.adj_matrix[u][v]]

    def incoming(self, v):
        # Tra ve danh sach cac dinh u co canh den v
        return [u for u in range(self.n) if self.adj_matrix[u][v]]

    def outgoing(self, v):
        # Tra ve danh sach cac dinh w ma v co canh den
        return [w for w in range(self.n) if self.adj_matrix[v][w]]

    def source(self, v, w):
        # Tra ve dinh nguon cua canh (v,w)
        return v if self.adj_matrix[v][w] else None

    def target(self, v, w):
        # Tra ve dinh dich cua canh (v,w)
        return w if self.adj_matrix[v][w] else None

# Vi du su dung
if __name__ == "__main__":
    g = Graph(4)
    g.add_edge(0, 1)
    g.add_edge(1, 2)
    print("Edges:", g.edges())            # [(0, 1), (1, 2)]
    print("Incoming to 1:", g.incoming(1)) # [0, 2]
    print("Outgoing from 1:", g.outgoing(1)) # [0, 2]
    print("Source (0,1):", g.source(0, 1))  # 0
    print("Target (0,1):", g.target(0, 1))  # 1