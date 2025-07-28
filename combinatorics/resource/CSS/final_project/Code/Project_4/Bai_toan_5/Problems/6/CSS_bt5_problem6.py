from collections import deque

class Tree:
    def __init__(self, n):
        # n: so dinh
        # adj: danh sach ke, dai dien cho cac canh
        self.n = n
        self.adj = [[] for _ in range(n)]

    def add_edge(self, u, v):
        # Them canh (u,v)
        self.adj[u].append(v)
        self.adj[v].append(u)

    def is_tree(self):
        # Kiem tra xem do thi co phai la cay
        # visited: trang thai tham
        # parent: cha cua moi dinh trong BFS
        if sum(len(edges) for edges in self.adj) // 2 != self.n - 1:
            return False
        visited = [False] * self.n
        parent = [-1] * self.n
        queue = deque([0])
        visited[0] = True

        while queue:
            u = queue.popleft()
            for v in self.adj[u]:
                if not visited[v]:
                    visited[v] = True
                    parent[v] = u
                    queue.append(v)
                elif v != parent[u]:
                    return False
        return all(visited)

# Vi du su dung
if __name__ == "__main__":
    t = Tree(4)
    t.add_edge(0, 1)
    t.add_edge(0, 2)
    t.add_edge(2, 3)
    print("Is tree:", t.is_tree())  # True