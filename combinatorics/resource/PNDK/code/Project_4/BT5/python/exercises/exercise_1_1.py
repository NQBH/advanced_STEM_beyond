class Graph:
    def __init__(self):
        self.vertices = set()
        self.edges = set()
    
    def add_edge(self, u, v):
        self.vertices.add(u)
        self.vertices.add(v)
        self.edges.add((min(u, v), max(u, v)))  # Undirected graph
    
    def get_dimacs_format(self):
        """Chuyển đồ thị sang định dạng DIMACS"""
        lines = []
        lines.append(f"p edge {len(self.vertices)} {len(self.edges)}")
        for u, v in sorted(self.edges):
            lines.append(f"e {u} {v}")
        return "\n".join(lines)
    
    @staticmethod
    def read_dimacs_file(filename):
        """Đọc đồ thị từ file DIMACS"""
        graph = Graph()
        try:
            with open(filename, 'r') as f:
                for line in f:
                    line = line.strip()
                    if line.startswith('c'):
                        # Comment line - bỏ qua
                        continue
                    elif line.startswith('p'):
                        # Problem line - p edge n m
                        parts = line.split()
                        if len(parts) >= 4:
                            n, m = int(parts[2]), int(parts[3])
                    elif line.startswith('e'):
                        # Edge line - e i j
                        parts = line.split()
                        if len(parts) >= 3:
                            u, v = int(parts[1]), int(parts[2])
                            graph.add_edge(u, v)
        except FileNotFoundError:
            print(f"File {filename} not found")
        return graph

def main():
    # Tạo đồ thị ví dụ
    g = Graph()
    g.add_edge(1, 2)
    g.add_edge(2, 3)
    g.add_edge(1, 3)
    g.add_edge(3, 4)
    
    # Ghi ra định dạng DIMACS
    print("DIMACS format:")
    print(g.get_dimacs_format())
    
    # Ghi vào file
    with open('sample.dimacs', 'w') as f:
        f.write(g.get_dimacs_format())
    
    # Đọc lại từ file
    print("\nReading from file:")
    g2 = Graph.read_dimacs_file('sample.dimacs')
    print(g2.get_dimacs_format())

if __name__ == "__main__":
    main()