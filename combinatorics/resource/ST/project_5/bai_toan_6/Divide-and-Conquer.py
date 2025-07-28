# Lop cay voi nhan va danh sach con
class TreeNode:
    def __init__(self, label):
        self.label = label                 # Luu nhan cua nut
        self.children = []                # Khoi tao danh sach con rong

# Ham chia de tri (Divide and Conquer)
def tree_edit_distance_dnc(t1, t2):
    if t1 is None and t2 is None:
        return 0
    if t1 is None:
        return 1 + sum(tree_edit_distance_dnc(None, c) for c in t2.children)
    if t2 is None:
        return 1 + sum(tree_edit_distance_dnc(c, None) for c in t1.children)

    # Tinh chi phi doi nhan
    cost = 0 if t1.label == t2.label else 1

    # Duyet ghep cac nut con
    m, n = len(t1.children), len(t2.children)

    def dfs(i, j):
        if i == m and j == n:
            return 0
        results = []
        if i < m and j < n:
            results.append(tree_edit_distance_dnc(t1.children[i], t2.children[j]) + dfs(i+1, j+1))
        if i < m:
            results.append(tree_edit_distance_dnc(t1.children[i], None) + dfs(i+1, j))
        if j < n:
            results.append(tree_edit_distance_dnc(None, t2.children[j]) + dfs(i, j+1))
        return min(results)

    return cost + dfs(0, 0)

# Ham nhap cay tu ban phim
def input_tree():
    label = input("Nhap nhan goc: ")
    node = TreeNode(label)
    n = int(input(f"So con cua {label}: "))
    for i in range(n):
        print(f"-- Con thu {i+1} cua {label}:")
        child = input_tree()
        node.children.append(child)
    return node

# Ham chinh
if __name__ == "__main__":
    print("Nhap cay 1:")
    t1 = input_tree()
    print("Nhap cay 2:")
    t2 = input_tree()
    print("Edit distance (D&C):", tree_edit_distance_dnc(t1, t2))