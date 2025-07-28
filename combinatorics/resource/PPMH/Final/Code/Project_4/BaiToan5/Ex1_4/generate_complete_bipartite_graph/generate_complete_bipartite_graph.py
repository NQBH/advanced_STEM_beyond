class Graph:
    def __init__(self):
        self.vertices = []
        self.edges = {}

    def add_vertex(self):
        v = len(self.vertices)
        self.vertices.append(v)
        self.edges[v] = []
        return v

    def add_edge(self, u, v):
        self.edges[u].append(v)
        self.edges[v].append(u)

    def display(self):
        for v in self.vertices:
            print(f"Đỉnh {v} nối với: {self.edges[v]}")

def generate_complete_bipartite_graph(p, q):
    G = Graph()
    left = [G.add_vertex() for _ in range(p)]
    right = [G.add_vertex() for _ in range(q)]
    for u in left:
        for v in right:
            G.add_edge(u, v)
    return G

p = int(input("Nhập số đỉnh tập trái p: "))
q = int(input("Nhập số đỉnh tập phải q: "))
graph = generate_complete_bipartite_graph(p, q)

graph.display()