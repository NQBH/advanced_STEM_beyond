class ExtendedAdjacencyMatrix:
    def __init__(self, n):
        """Khởi tạo ma trận kề mở rộng cho n đỉnh (đánh số từ 0 đến n-1)"""
        self.n = n
        self.matrix = [[0] * n for _ in range(n)]
    
    def add_edge(self, v, w):
        """Thêm cạnh từ v đến w"""
        if 0 <= v < self.n and 0 <= w < self.n:
            self.matrix[v][w] = 1
    
    def del_edge(self, v, w):
        """Xóa cạnh từ v đến w"""
        if 0 <= v < self.n and 0 <= w < self.n:
            self.matrix[v][w] = 0
    
    def has_edge(self, v, w):
        """Kiểm tra có cạnh từ v đến w không"""
        if 0 <= v < self.n and 0 <= w < self.n:
            return self.matrix[v][w] != 0
        return False
    
    def edges(self):
        """Trả về danh sách tất cả các cạnh"""
        result = []
        for i in range(self.n):
            for j in range(self.n):
                if self.matrix[i][j]:
                    result.append((i, j))
        return result
    
    def incoming(self, v):
        """Trả về danh sách các đỉnh có cạnh vào v"""
        if not (0 <= v < self.n):
            return []
        result = []
        for i in range(self.n):
            if self.matrix[i][v]:
                result.append(i)
        return result
    
    def outgoing(self, v):
        """Trả về danh sách các đỉnh có cạnh ra từ v"""
        if not (0 <= v < self.n):
            return []
        result = []
        for j in range(self.n):
            if self.matrix[v][j]:
                result.append(j)
        return result
    
    def source(self, v, w):
        """Kiểm tra v có là nguồn của cạnh đến w không"""
        return self.has_edge(v, w)
    
    def target(self, v, w):
        """Kiểm tra w có là đích của cạnh từ v không"""
        return self.has_edge(v, w)
    
    def display(self):
        """Hiển thị ma trận"""
        print("Adjacency Matrix:")
        for row in self.matrix:
            print(row)

def main():
    # Tạo đồ thị 4 đỉnh
    g = ExtendedAdjacencyMatrix(4)
    
    # Thêm một số cạnh
    g.add_edge(0, 1)
    g.add_edge(1, 2)
    g.add_edge(2, 3)
    g.add_edge(0, 3)
    
    print("Graph representation:")
    g.display()
    
    print(f"\nAll edges: {g.edges()}")
    print(f"Incoming to vertex 2: {g.incoming(2)}")
    print(f"Outgoing from vertex 0: {g.outgoing(0)}")
    print(f"Is there edge from 0 to 1? {g.source(0, 1)}")
    print(f"Is vertex 3 target of edge from 0? {g.target(0, 3)}")

if __name__ == "__main__":
    main()