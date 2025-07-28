# Lop dinh nghia cay
class TreeNode:
    def __init__(self, label):
        self.label = label                 # Luu nhan cua nut
        self.children = []                # Danh sach cac nut con

# Ham duyet hau tu
def postorder_traversal(node):
    if node is None:
        return
    for child in node.children:
        postorder_traversal(child)        # B1: Duyet cac nut con truoc
    print(node.label)                     # B2: Xuat nhan cua nut hien tai

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
    print("Duyet hau tu:")
    postorder_traversal(root)