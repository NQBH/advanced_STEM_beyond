import collections

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        # Danh sách kề là dạng biểu diễn chính
        self.adj = [[] for _ in range(vertices)]

    def add_edge(self, u, v):
        """Thêm cạnh vô hướng"""
        self.adj[u].append(v)
        self.adj[v].append(u)

    def to_adjacency_matrix(self):
        """Chuyển đổi sang Ma trận kề"""
        matrix = [[0] * self.V for _ in range(self.V)]
        for u in range(self.V):
            for v in self.adj[u]:
                matrix[u][v] += 1
        return matrix

    def to_adjacency_map(self):
        """Chuyển đổi sang Ánh xạ kề (dictionary)"""
        adj_map = {i: self.adj[i] for i in range(self.V) if self.adj[i]}
        return adj_map

    def print_adj_list(self):
        print("Danh sach ke:")
        for i in range(self.V):
            print(f"{i}: {self.adj[i]}")

class Tree(Graph):
    def to_parent_array(self, root):
        """Chuyển đổi sang Mảng Cha, yêu cầu một đỉnh gốc"""
        parent = [-1] * self.V  # -1 cho gốc và các đỉnh không kết nối
        visited = {root}
        queue = collections.deque([root])

        while queue:
            u = queue.popleft()
            for v in self.adj[u]:
                if v not in visited:
                    visited.add(v)
                    parent[v] = u
                    queue.append(v)
        return parent

if __name__ == "__main__":
    print("--- Bieu dien Do thi ---")
    g = Graph(4)
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(2, 3)
    g.add_edge(1, 2)  # Thêm cạnh song song

    g.print_adj_list()
    
    matrix = g.to_adjacency_matrix()
    print("\nMa tran ke:")
    for row in matrix:
        print(row)

    print("\n--- Bieu dien Cay ---")
    t = Tree(5)
    t.add_edge(0, 1)
    t.add_edge(0, 2)
    t.add_edge(1, 3)
    t.add_edge(1, 4)

    t.print_adj_list()

    parent_array = t.to_parent_array(0)
    print("\nMang Cha (goc la 0):")
    for i, p in enumerate(parent_array):
        print(f"parent[{i}] = {p}")