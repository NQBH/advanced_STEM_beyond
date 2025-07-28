class ExtendedFCNS:
    def __init__(self, n):
        self.n = n
        self.root = None  #lưu chỉ số root
        self.first_child = [None] * n  #first_child[v] = con đầu tiên của v
        self.next_sibling = [None] * n  #next_sibling[v] = sibling kế tiếp của v
        self.num_children = [0] * n  #số con của mỗi node
        self.parent = [None] * n

    def set_root(self, r):
        self.root = r

    def add_child(self, parent, child):
        #thêm child vào đầu danh sách con của parent
        self.next_sibling[child] = self.first_child[parent]
        self.first_child[parent] = child
        self.parent[child] = parent
        self.num_children[parent] += 1

    def root_node(self):
        return self.root

    def number_of_children(self, v):
        return self.num_children[v]

    def children(self, v):
        #trả về con trỏ tới con đầu tiên của v
        return self.first_child[v]

    #duyệt các con của node v
    def iterate_children(self, v):
        c = self.first_child[v]
        while c is not None:
            yield c
            c = self.next_sibling[c]

#ví dụ
if __name__ == "__main__":
    tree = ExtendedFCNS(7)
    tree.set_root(0)
    tree.add_child(0, 1)
    tree.add_child(0, 2)
    tree.add_child(1, 3)
    tree.add_child(1, 4)
    tree.add_child(2, 5)
    tree.add_child(2, 6)

    print("Root:", tree.root_node())
    print("Number of children of node 0:", tree.number_of_children(0))
    print("Children of node 0:", list(tree.iterate_children(0)))
    print("Number of children of node 1:", tree.number_of_children(1))
    print("Children of node 1:", list(tree.iterate_children(1)))
