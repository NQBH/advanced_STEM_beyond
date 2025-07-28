# Lop cay voi nhan va danh sach con
class TreeNode:
    def __init__(self, label):
        self.label = label                 # Luu nhan cua nut
        self.children = []                # Khoi tao danh sach con rong

# Ham tinh khoang cach giua hai cay bang Branch-and-Bound
def tree_edit_distance_bnb(t1, t2):
    best_cost = [float('inf')]  # Chi phi nho nhat tim duoc

    def recurse(t1, t2, acc):
        if acc >= best_cost[0]:
            return float('inf')
        if t1 is None and t2 is None:
            best_cost[0] = min(best_cost[0], acc)
            return 0
        if t1 is None:
            cost = 1 + sum(recurse(None, c, acc+1) for c in t2.children)
            best_cost[0] = min(best_cost[0], acc + cost)
            return cost
        if t2 is None:
            cost = 1 + sum(recurse(c, None, acc+1) for c in t1.children)
            best_cost[0] = min(best_cost[0], acc + cost)
            return cost

        cost = 0 if t1.label == t2.label else 1
        m, n = len(t1.children), len(t2.children)
        min_sub = float('inf')

        def dfs(i, j, sub_cost):
            nonlocal min_sub
            if sub_cost >= min_sub: return
            if i == m and j == n:
                min_sub = min(min_sub, sub_cost)
                return
            if i < m and j < n:
                dfs(i+1, j+1, sub_cost + recurse(t1.children[i], t2.children[j], acc + cost + sub_cost))
            if i < m:
                dfs(i+1, j, sub_cost + recurse(t1.children[i], None, acc + cost + sub_cost))
            if j < n:
                dfs(i, j+1, sub_cost + recurse(None, t2.children[j], acc + cost + sub_cost))

        dfs(0, 0, 0)
        total = cost + min_sub
        best_cost[0] = min(best_cost[0], acc + total)
        return total

    return recurse(t1, t2, 0)

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

if __name__ == "__main__":
    print("Nhap cay 1:")
    t1 = input_tree()
    print("Nhap cay 2:")
    t2 = input_tree()
    print("Edit distance (BnB):", tree_edit_distance_bnb(t1, t2))