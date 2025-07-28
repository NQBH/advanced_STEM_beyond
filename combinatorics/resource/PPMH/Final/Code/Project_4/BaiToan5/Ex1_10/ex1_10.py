class ExtendedTree:
    def __init__(self, n):
        self.n = n
        self.first_child = [None] * n
        self.next_sibling = [None] * n
        self.parent = [None] * n
        self.num_children = [0] * n
        self.children_list = [[] for _ in range(n)]
        self.root = None

    def set_root(self, v):
        self.root = v

    def add_child(self, parent, child):
        self.parent[child] = parent
        self.next_sibling[child] = self.first_child[parent]
        self.first_child[parent] = child
        self.num_children[parent] += 1
        self.children_list[parent].insert(0, child)  

    def get_root(self):
        return self.root

    def number_of_children(self, v):
        return self.num_children[v]

    def children(self, v):
        return self.children_list[v]

tree = ExtendedTree(7)
tree.set_root(0)
tree.add_child(0, 1)
tree.add_child(0, 2)
tree.add_child(1, 3)
tree.add_child(1, 4)
tree.add_child(2, 5)
tree.add_child(2, 6)

print("Root:", tree.get_root())
print("Children of 0:", tree.children(0))
print("Number of children of 1:", tree.number_of_children(1))
print("Children of 2:", tree.children(2))
