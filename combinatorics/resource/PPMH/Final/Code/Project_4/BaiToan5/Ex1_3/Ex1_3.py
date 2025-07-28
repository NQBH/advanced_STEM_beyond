class Graph:
    def __init__(self):
        self._adj = {}
        self._edges = []

    def add_vertex(self):
        v = len(self._adj)
        self._adj[v] = []
        return v

    def add_edge(self, u, v):
        self._adj[u].append(v)
        self._adj[v].append(u)  # đồ thị vô hướng
        self._edges.append((u, v))

    def vertices(self):
        return list(self._adj.keys())

    def edges(self):
        return self._edges

    def print_graph(self):
        for v in self.vertices():
            print(f"{v}: {self._adj[v]}")


def generate_path_graph(n):
    G = Graph()
    verts = [G.add_vertex() for _ in range(n)]
    for i in range(n - 1):
        G.add_edge(verts[i], verts[i + 1])
    return G

def generate_circle_graph(n):
    G = generate_path_graph(n)
    G.add_edge(0, n - 1)
    return G

def generate_wheel_graph(n):
    if n < 4:
        raise ValueError("Wheel graph requires at least 4 vertices.")
    G = Graph()
    cycle = [G.add_vertex() for _ in range(n - 1)]
    center = G.add_vertex()
    for i in range(n - 1):
        G.add_edge(cycle[i], cycle[(i + 1) % (n - 1)])
        G.add_edge(center, cycle[i])
    return G


if __name__ == "__main__":
    n = int(input("Nhập n: "))

    print("\nĐồ thị P_n (đường đi):")
    G1 = generate_path_graph(n)
    G1.print_graph()

    print("\nĐồ thị C_n (chu trình):")
    G2 = generate_circle_graph(n)
    G2.print_graph()

    if n >= 4:
        print("\nĐồ thị W_n (bánh xe):")
        G3 = generate_wheel_graph(n)
        G3.print_graph()
    else:
        print("\nKhông thể tạo W_n với n < 4.")
