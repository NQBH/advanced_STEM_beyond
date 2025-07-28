# Lop cay voi nhan va danh sach con
class TreeNode:
    def __init__(self, label):
        self.label = label                 # Luu nhan cua nut
        self.children = []                # Khoi tao danh sach con rong

# Ham tinh khoang cach chinh sua giua hai cay bang backtracking
def tree_edit_distance(t1, t2):
    if t1 is None and t2 is None:         # Neu ca hai cay rong
        return 0                          # -> khoang cach la 0
    if t1 is None:                        # Neu chi co t1 rong
        # Phai chen nut t2 va tat ca con cua no
        return 1 + sum(tree_edit_distance(None, child) for child in t2.children)
    if t2 is None:                        # Neu chi co t2 rong
        # Phai xoa nut t1 va tat ca con cua no
        return 1 + sum(tree_edit_distance(child, None) for child in t1.children)
    
    # Neu nhan giong nhau thi chi phi la 0, nguoc lai la 1
    cost = 0 if t1.label == t2.label else 1

    # Lay so luong con cua hai nut
    m, n = len(t1.children), len(t2.children)
    min_cost = float('inf')              # Dat chi phi nho nhat ban dau vo cung

    # Ham de quy thu tat ca cach ghep con giua hai cay
    def dfs(i, j, acc):                  # acc: tong chi phi hien tai
        nonlocal min_cost
        if i == m and j == n:            # Neu da ghep het tat ca con
            min_cost = min(min_cost, acc) # Cap nhat chi phi nho nhat
            return
        if i < m and j < n:
            # Ghep con thu i cua t1 voi con thu j cua t2
            dfs(i+1, j+1, acc + tree_edit_distance(t1.children[i], t2.children[j]))
        if i < m:
            # Xoa con thu i cua t1
            dfs(i+1, j, acc + tree_edit_distance(t1.children[i], None))
        if j < n:
            # Chen con thu j cua t2
            dfs(i, j+1, acc + tree_edit_distance(None, t2.children[j]))
    
    dfs(0, 0, 0)                         # Bat dau ghep tu con dau tien cua hai nut
    return cost + min_cost               # Tong chi phi = chi phi doi nhan + ghep con

# Ham nhap cay tu ban phim
def input_tree():
    label = input("Nhap nhan goc: ")     # Nhap nhan cua nut hien tai
    node = TreeNode(label)               # Tao nut moi
    n = int(input(f"So con cua {label}: ")) # Nhap so luong con
    for i in range(n):
        print(f"-- Con thu {i+1} cua {label}:")
        child = input_tree()             # Nhap de quy nut con
        node.children.append(child)      # Them con vao danh sach
    return node                          # Tra ve cay vua nhap

# Chuong trinh chinh
if __name__ == "__main__":
    print("Nhap cay 1:")
    t1 = input_tree()                    # Nhap cay thu nhat
    print("Nhap cay 2:")
    t2 = input_tree()                    # Nhap cay thu hai
    print("Edit distance:", tree_edit_distance(t1, t2))  # Tinh va in ket qua