from collections import deque

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class CompleteBinaryTree:
    def __init__(self):
        self.root = None
        self.count = 0

    def add_node(self, val):
        new_node = Node(val)
        if not self.root:
            self.root = new_node
            return new_node
        
        q = deque()
        q.append(self.root)

        while q:
            node = q.popleft()
            if not node.left:
                node.left = new_node
                return new_node
            elif not node.right:
                node.right = new_node
                return new_node
            else:
                q.append(node.left)
                q.append(node.right)

    def build_tree(self, n):
        for i in range(1, n + 1):
            self.add_node(i)

    def print_level_order(self):
        if not self.root:
            return
        q = deque()
        q.append(self.root)
        while q:
            node = q.popleft()
            print(node.val, end=' ')
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

n = int(input("Nhập số nút n: "))
tree = CompleteBinaryTree()
tree.build_tree(n)
print("Cây nhị phân đầy đủ (duyệt theo tầng):")
tree.print_level_order()