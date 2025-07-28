class BinaryTree:
    def __init__(self):
        self.nodes = []
        self.children_list = []
        self._root = None

    def new_node(self):
        node_id = len(self.nodes)
        self.nodes.append(node_id)
        self.children_list.append([])
        if self._root is None:
            self._root = node_id
        return node_id

    def root(self):
        return self._root

    def children(self, v):
        return self.children_list[v]

def generate_complete_binary_tree(T, n):
    nodes = []
    for _ in range(n):
        nodes.append(T.new_node())
    T._root = nodes[0]

    for i in range((n - 2) // 2 + 1):
        left = 2 * i + 1
        right = 2 * i + 2
        if left < n:
            T.children(nodes[i]).append(nodes[left])
        if right < n:
            T.children(nodes[i]).append(nodes[right])

if __name__ == "__main__":
    T = BinaryTree()
    n = 7
    generate_complete_binary_tree(T, n)

    print("Số node:", T.nodes.__len__())
    print("Root:", T.root())
    print("Danh sách cạnh (cha -> con):")
    edges = []
    for parent in T.nodes:
        for child in T.children(parent):
            edges.append((parent, child))
    print(edges)