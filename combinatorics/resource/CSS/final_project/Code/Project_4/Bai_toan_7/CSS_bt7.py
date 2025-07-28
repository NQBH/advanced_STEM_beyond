class Tree:
    def __init__(self, vertices):
        self.n = vertices
        self.adj = [[] for _ in range(vertices)]

    def add_edge(self, parent, child):
        self.adj[parent].append(child)

    def preorder(self, v):
        print(v, end=" ")
        for child in self.adj[v]:
            self.preorder(child)

    def postorder(self, v):
        for child in self.adj[v]:
            self.postorder(child)
        print(v, end=" ")

    def top_down(self, v):
        self.preorder(v)  # Top-down is equivalent to preorder

    def bottom_up(self, v):
        self.postorder(v)  # Bottom-up is equivalent to postorder

# Example usage
if __name__ == "__main__":
    t = Tree(5)
    t.add_edge(0, 1)
    t.add_edge(0, 2)
    t.add_edge(1, 3)
    t.add_edge(1, 4)
    print("Preorder:", end=" ")
    t.preorder(0)
    print()
    print("Postorder:", end=" ")
    t.postorder(0)
    print()
    print("Top-down:", end=" ")
    t.top_down(0)
    print()
    print("Bottom-up:", end=" ")
    t.bottom_up(0)
    print()