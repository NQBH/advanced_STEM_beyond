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

def generate_complete_graph(n):
    G = Graph()
    vertices = [G.add_vertex() for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            G.add_edge(vertices[i], vertices[j])
    return G

n = int(input("Nhập số đỉnh n: "))
graph = generate_complete_graph(n)
graph.display()