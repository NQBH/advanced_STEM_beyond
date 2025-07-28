from collections import deque

# Lop dinh nghia cay
class TreeNode:
    def __init__(self, label):
        self.label = label                  # Luu nhan cua nut
        self.children = []                 # Danh sach cac nut con

# Ham duyet top-down bang queue (level-order)
def topdown_traversal(root):
    if root is None:
        return
    q = deque()
    q.append(root)
    while q:
        node = q.popleft()                # Lay nut dau hang doi
        print(node.label)                 # In nhan cua nut
        for child in node.children:
            q.append(child)               # Dua cac nut con vao hang doi

# Ham nhap cay tu ban phim
def input_tree():
    label = input("Nhap nhan nut: ")
    node = TreeNode(label)
    n = int(input(f"So con cua {label}: "))
    for i in range(n):
        print(f"-- Con thu {i+1} cua {label}:")
        child = input_tree()
        node.children.append(child)
    return node

# Ham chinh
if __name__ == "__main__":
    print("Nhap cay:")
    root = input_tree()
    print("Duyet top-down:")
    topdown_traversal(root)