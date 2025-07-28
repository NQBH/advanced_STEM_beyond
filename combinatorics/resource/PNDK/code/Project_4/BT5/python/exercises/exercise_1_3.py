class GraphOperations:
    @staticmethod
    def create_path_graph(n):
        """Tạo đồ thị đường Pn"""
        if n <= 0:
            return [], []
        
        vertices = list(range(1, n + 1))
        edges = []
        
        for i in range(1, n):
            edges.append((i, i + 1))
        
        return vertices, edges
    
    @staticmethod
    def create_circle_graph(n):
        """Tạo đồ thị vòng Cn"""
        if n <= 0:
            return [], []
        
        vertices = list(range(1, n + 1))
        edges = []
        
        # Thêm các cạnh liên tiếp
        for i in range(1, n):
            edges.append((i, i + 1))
        
        # Thêm cạnh nối cuối về đầu
        if n > 1:
            edges.append((n, 1))
        
        return vertices, edges
    
    @staticmethod
    def create_wheel_graph(n):
        """Tạo đồ thị bánh xe Wn (n-1 đỉnh vòng + 1 đỉnh trung tâm)"""
        if n <= 1:
            return [], []
        
        # n đỉnh: 1 đến n (đỉnh n là trung tâm)
        vertices = list(range(1, n + 1))
        edges = []
        
        center = n  # Đỉnh trung tâm
        
        # Tạo vòng tròn từ 1 đến n-1
        for i in range(1, n):
            edges.append((i, i + 1 if i + 1 < n else 1))
        
        # Nối tất cả đỉnh vòng với trung tâm
        for i in range(1, n):
            edges.append((i, center))
        
        return vertices, edges

def main():
    ops = GraphOperations()
    
    print("Path Graph P5:")
    vertices, edges = ops.create_path_graph(5)
    print(f"Vertices: {vertices}")
    print(f"Edges: {edges}")
    
    print("\nCircle Graph C5:")
    vertices, edges = ops.create_circle_graph(5)
    print(f"Vertices: {vertices}")
    print(f"Edges: {edges}")
    
    print("\nWheel Graph W5:")
    vertices, edges = ops.create_wheel_graph(5)
    print(f"Vertices: {vertices}")
    print(f"Edges: {edges}")

if __name__ == "__main__":
    main()