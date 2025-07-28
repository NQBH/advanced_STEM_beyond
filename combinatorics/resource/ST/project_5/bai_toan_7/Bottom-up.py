# Lop dinh nghia cay
class TreeNode:
    def __init__(self, label):
        self.label = label                  # Luu nhan cua nut
        self.children = []                 # Danh sach cac nut con

# Duyet bottom-up bang de quy
def bottomup_traversal(node):
    if node is None:
        return
    for child in node.children:            # Duyet tat ca con truoc
        bottomup_traversal(child)
    print(node.label)                      # Sau khi duyet con moi in nut hien tai

# Ham nhap cay
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
    print("Duyet bottom-up:")
    bottomup_traversal(root)