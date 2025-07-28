class Graph:
    def __init__(self, n):
        self.n = n
        self.matrix = [[0] * n for _ in range(n)]
    
    def add_edge(self, v, w):
        if 0 <= v < self.n and 0 <= w < self.n:
            self.matrix[v][w] = 1
    
    def del_edge(self, v, w):
        if 0 <= v < self.n and 0 <= w < self.n:
            self.matrix[v][w] = 0
    
    def edges(self):
        result = []
        for i in range(self.n):
            for j in range(self.n):
                if self.matrix[i][j]:
                    result.append((i, j))
        return result
    
    def incoming(self, v):
        if not (0 <= v < self.n):
            return []
        result = []
        for i in range(self.n):
            if self.matrix[i][v]:
                result.append(i)
        return result
    
    def outgoing(self, v):
        if not (0 <= v < self.n):
            return []
        result = []
        for j in range(self.n):
            if self.matrix[v][j]:
                result.append(j)
        return result
    
    def source(self, v, w):
        if 0 <= v < self.n and 0 <= w < self.n:
            return self.matrix[v][w] != 0
        return False
    
    def target(self, v, w):
        if 0 <= v < self.n and 0 <= w < self.n:
            return self.matrix[v][w] != 0
        return False
    
    def display(self):
        for row in self.matrix:
            print(row)

def main():
    # Test với đồ thị 3 đỉnh
    g = Graph(3)
    g.add_edge(0, 1)
    g.add_edge(1, 2)
    g.add_edge(0, 2)
    
    print("Graph matrix:")
    g.display()
    
    print(f"\nEdges: {g.edges()}")
    print(f"Incoming to 2: {g.incoming(2)}")
    print(f"Outgoing from 0: {g.outgoing(0)}")
    print(f"Is 0 connected to 1? {g.source(0, 1)}")
    print(f"Is 1 target of 0? {g.target(0, 1)}")

if __name__ == "__main__":
    main()