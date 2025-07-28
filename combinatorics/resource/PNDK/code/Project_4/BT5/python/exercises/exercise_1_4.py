class GraphGenerator:
    @staticmethod
    def create_complete_graph(n):
        """Tạo đồ thị đầy đủ Kn"""
        if n <= 0:
            return [], []
        
        vertices = list(range(1, n + 1))
        edges = []
        
        # Mỗi đỉnh nối với tất cả các đỉnh khác
        for i in range(1, n + 1):
            for j in range(i + 1, n + 1):
                edges.append((i, j))
        
        return vertices, edges
    
    @staticmethod
    def create_complete_bipartite_graph(p, q):
        """Tạo đồ thị hai phía đầy đủ Kp,q"""
        if p <= 0 or q <= 0:
            return [], []
        
        vertices = list(range(1, p + q + 1))
        edges = []
        
        # Mỗi đỉnh tập 1 nối với mỗi đỉnh tập 2
        for i in range(1, p + 1):
            for j in range(p + 1, p + q + 1):
                edges.append((i, j))
        
        return vertices, edges

def main():
    gen = GraphGenerator()
    
    print("Complete Graph K4:")
    vertices, edges = gen.create_complete_graph(4)
    print(f"Vertices: {vertices}")
    print(f"Edges: {edges}")
    print(f"Number of edges: {len(edges)}")
    
    print("\nComplete Bipartite Graph K2,3:")
    vertices, edges = gen.create_complete_bipartite_graph(2, 3)
    print(f"Vertices: {vertices}")
    print(f"Edges: {edges}")
    print(f"Number of edges: {len(edges)}")

if __name__ == "__main__":
    main()