class TreeNode:
    def __init__(self, value):
        # value: gia tri cua nut
        # first_child: chi so cua con dau tien
        # next_sibling: chi so cua anh em ke tiep
        # parent: chi so cua cha
        # num_children: so con truc tiep
        self.value = value
        self.first_child = None
        self.next_sibling = None
        self.parent = None
        self.num_children = 0

class Tree:
    def __init__(self, n):
        # n: so nut toi da
        # nodes: mang luu cac nut
        # root_node: chi so cua nut goc
        # next_idx: chi so tiep theo de cap phat
        self.n = n
        self.nodes = [None] * n
        self.root_node = None
        self.next_idx = 0

    def set_root(self, value):
        # thiet lap nut goc
        self.nodes[0] = TreeNode(value)
        self.root_node = 0
        self.next_idx = 1

    def add_child(self, parent_idx, value):
        # them con vao nut parent_idx
        if self.next_idx >= self.n:
            raise ValueError("Tree is full")
        new_node_idx = self.next_idx
        self.nodes[new_node_idx] = TreeNode(value)
        self.nodes[new_node_idx].parent = parent_idx
        if self.nodes[parent_idx].first_child is None:
            self.nodes[parent_idx].first_child = new_node_idx
        else:
            current = self.nodes[parent_idx].first_child
            while self.nodes[current].next_sibling is not None:
                current = self.nodes[current].next_sibling
            self.nodes[current].next_sibling = new_node_idx
        self.nodes[parent_idx].num_children += 1
        self.next_idx += 1

    def parent(self, v):
        return self.nodes[v].parent

    def first_child(self, v):
        return self.nodes[v].first_child

    def next_sibling(self, v):
        return self.nodes[v].next_sibling

    def number_of_children(self, v):
        return self.nodes[v].num_children

# Vi du su dung
if __name__ == "__main__":
    t = Tree(5)
    t.set_root(0)
    t.add_child(0, 1)
    t.add_child(0, 2)
    t.add_child(0, 3)
    print("Number of children of root:", t.number_of_children(0))  # 3
    print("First child of root:", t.first_child(0))                # 1
    print("Next sibling of first child:", t.next_sibling(1))       # 2
    print("Parent of node 2:", t.parent(2))                         # 0