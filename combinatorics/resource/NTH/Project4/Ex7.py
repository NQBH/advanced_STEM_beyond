import collections

class Node:
    """Định nghĩa một nút trong cây."""
    def __init__(self, data):
        self.data = data
        self.children = []

def preorder(root):
    """(a) Duyệt Tiền thứ tự (Preorder Traversal)"""
    if root is None:
        return
    print(root.data, end=" ")
    for child in root.children:
        preorder(child)

def postorder(root):
    """(b) Duyệt Hậu thứ tự (Postorder Traversal)"""
    if root is None:
        return
    for child in root.children:
        postorder(child)
    print(root.data, end=" ")

def top_down(root):
    """(c) Duyệt từ trên xuống (Top-down / Level-order)"""
    if root is None:
        return
    queue = collections.deque([root])
    while queue:
        current = queue.popleft()
        print(current.data, end=" ")
        for child in current.children:
            queue.append(child)

def bottom_up(root):
    """(d) Duyệt từ dưới lên (Bottom-up)"""
    if root is None:
        return
    queue = collections.deque([root])
    stack = []
    
    # Bước 1: Duyệt BFS và đẩy các nút vào stack
    while queue:
        current = queue.popleft()
        stack.append(current)
        # Thêm con vào queue từ phải sang trái
        for child in reversed(current.children):
            queue.append(child)
    
    # Bước 2: Lấy các nút ra khỏi stack và in
    while stack:
        print(stack.pop().data, end=" ")

if __name__ == "__main__":
    # Xây dựng cây ví dụ
    root = Node('F')
    b_node = Node('B')
    g_node = Node('G')
    i_node = Node('I')
    root.children.extend([b_node, g_node, i_node])
    
    a_node = Node('A')
    d_node = Node('D')
    b_node.children.extend([a_node, d_node])
    
    c_node = Node('C')
    e_node = Node('E')
    d_node.children.extend([c_node, e_node])
    
    h_node = Node('H')
    i_node.children.append(h_node)

    print("Duyet Tien thu tu (Preorder):  ", end="")
    preorder(root)
    print()

    print("Duyet Hau thu tu (Postorder):  ", end="")
    postorder(root)
    print()

    print("Duyet Tu tren xuong (Top-down): ", end="")
    top_down(root)
    print()

    print("Duyet Tu duoi len (Bottom-up): ", end="")
    bottom_up(root)
    print()