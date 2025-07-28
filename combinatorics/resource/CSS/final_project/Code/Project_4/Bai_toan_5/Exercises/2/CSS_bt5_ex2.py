class SGBGraph:
    def __init__(self):
        # n: so dinh
        # m: so canh
        # adj: danh sach ke
        # labels: nhan cua cac dinh
        self.n = 0
        self.m = 0
        self.adj = []
        self.labels = []

    def read_sgb(self, filename):
        # Doc file SGB de xay dung do thi
        with open(filename, 'r') as f:
            lines = f.readlines()
        header = lines[0].strip().split()
        self.n = int(header[3][:-1])
        self.m = int(header[4][:-1])
        self.adj = [[] for _ in range(self.n)]
        self.labels = [''] * self.n

        vertex_section = False
        arc_section = False
        for line in lines[1:]:
            line = line.strip()
            if line.startswith('* Vertices'):
                vertex_section = True
                continue
            if line.startswith('* Arcs'):
                vertex_section = False
                arc_section = True
                continue
            if vertex_section:
                parts = line.split(',')
                v = int(parts[0])
                self.labels[v] = parts[1].strip()
            if arc_section:
                parts = line.split(',')
                v = int(parts[0])
                u = int(self.labels.index(parts[1].strip()))
                self.adj[u].append(v)

    def write_sgb(self, filename):
        # Ghi do thi ra file SGB
        with open(filename, 'w') as f:
            f.write(f"* GraphBase graph(utiltypes..., {self.n}, {self.m})\n")
            f.write("Graph description\n")
            f.write("* Vertices\n")
            for i in range(self.n):
                f.write(f"{i}, v{i}, 0, 0\n")
            f.write("* Arcs\n")
            edge_id = 0
            for u in range(self.n):
                for v in self.adj[u]:
                    f.write(f"{v}, {edge_id}, 0, 0\n")
                    edge_id += 1
            f.write("* Checksum\n")

# Vi du su dung
if __name__ == "__main__":
    g = SGBGraph()
    # g.read_sgb("input.txt")
    # g.write_sgb("output.txt")