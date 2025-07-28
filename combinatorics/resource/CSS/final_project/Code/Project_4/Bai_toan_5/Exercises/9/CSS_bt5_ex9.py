class Tree:
    def __init__(self, n):
        # n: so nut trong cay
        # parent: mang cha
        # children: danh sach con
        self.n = n
        self.parent = [-1] * n
        self.children = [[] for _ in range(n)]

    def add_edge(self, u, v):
        # Them canh (u,v), tuc u la cha cua v
        self.parent[v] = u
        self.children[u].append(v)

    def previous_sibling(self, v):
        # Tim anh em truoc cua nut v
        if self.parent[v] == -1:
            return None
        siblings = self.children[self.parent[v]]
        idx = siblings.index(v)
        return siblings[idx - 1] if idx > 0 else None

# Vi du su dung
if __name__ == "__main__":
    t = Tree(5)
    t.add_edge(0, 1)
    t.add_edge(0, 2)
    t.add_edge(0, 3)
    print("Previous sibling of 2:", t.previous_sibling(2))  % 1
    print("Previous sibling of 1:", t.previous_sibling(1))  # None