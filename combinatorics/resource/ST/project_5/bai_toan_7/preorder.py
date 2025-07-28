# Lop dinh nghia cay
class TreeNode:
    def __init__(self, label):
        self.label = label                 # Luu nhan cua nut
        self.children = []                # Danh sach cac nut con

# Ham duyet tien tu
def preorder_traversal(node):
    if node is None:
        return
    print(node.label)                     # B1: Xuat nhan cua nut hien tai
    for child in node.children:
        preorder_traversal(child)         # B2: Duyet cac nut con

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
    print("Duyet tien tu:")
    preorder_traversal(root)