class TreeNode:
    def __init__(self, value):
        # value: gia tri cua nut
        # first_child: con tro den con dau tien
        # next_sibling: con tro den anh em ke tiep
        # parent: con tro den cha
        # num_children: so con truc tiep
        self.value = value
        self.first_child = None
        self.next_sibling = None
        self.parent = None
        self.num_children = 0

class Tree:
    def __init__(self):
        self.root_node = None

    def set_root(self, value):
        # Thiet lap goc cua cay
        self.root_node = TreeNode(value)

    def add_child(self, parent, value):
        # Them con vao nut parent
        new_node = TreeNode(value)
        new_node.parent = parent
        if not parent.first_child:
            parent.first_child = new_node
        else:
            current = parent.first_child
            while current.next_sibling:
                current = current.next_sibling
            current.next_sibling = new_node
        parent.num_children += 1

    def parent(self, v):
        # Tra ve cha cua nut v
        return v.parent

    def first_child(self, v):
        # Tra ve con dau tien cua nut v
        return v.first_child

    def next_sibling(self, v):
        # Tra ve anh em ke tiep cua nut v
        return v.next_sibling

    def number_of_children(self, v):
        # Tra ve so con cua nut v
        return v.num_children

# Vi du su dung
if __name__ == "__main__":
    t = Tree()
    t.set_root(0)
    t.add_child(t.root_node, 1)
    t.add_child(t.root_node, 2)
    print("Number of children of root:", t.number_of_children(t.root_node))  # 2
    print("First child of root:", t.first_child(t.root_node).value)         # 1
    print("Next sibling of first child:", t.next_sibling(t.first_child(t.root_node)).value)  # 2