class Graph:
    def __init__(self, n):
        self.n = n
        self.adj_matrix = [[0]*n for _ in range(n)]
    def add_edge(self, u, v):
        # Them canh (u,v)
        self.adj_matrix[u][v] = 1
        self.adj_matrix[v][u] = 1
    def edges(self):
        # Tra ve cac cap (u,v) voi u < v
        return [(u, v)
                for u in range(self.n)
                for v in range(u+1, self.n)
                if self.adj_matrix[u][v]]

class UF:
    def __init__(self, n):
        self.parent = list(range(n))
        self.count = n
    def find(self, u):
        # Path compression
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]
    def union(self, u, v):
        ru, rv = self.find(u), self.find(v)
        if ru == rv:
            return False
        self.parent[rv] = ru
        self.count -= 1
        return True

def enumerate_spanning_trees(G):
    n = G.n
    E = G.edges()
    all_trees = []
    chosen = []

    def backtrack(idx):
        if len(chosen) == n - 1:
            uf = UF(n)
            for u, v in chosen:
                if not uf.union(u, v):
                    return
            if uf.count == 1:
                all_trees.append(chosen.copy())
            return
        if idx == len(E):
            return
        # Bo chon E[idx]
        backtrack(idx + 1)
        # Chon E[idx]
        chosen.append(E[idx])
        backtrack(idx + 1)
        chosen.pop()

    backtrack(0)
    return all_trees

if __name__ == "__main__":
    G = Graph(7)
    # Chuyen 1-based -> 0-based
    for u, v in [(1,2),(1,3),(3,6),(6,4),(4,1),
                 (2,4),(4,7),(7,2),(2,5),(5,7),(6,7)]:
        G.add_edge(u-1, v-1)
    trees = enumerate_spanning_trees(G)
    print("So spanning trees tim duoc:", len(trees))