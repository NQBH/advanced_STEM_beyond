def read_tree():
    n = int(input("Nhap so dinh n: "))
    print(f"Nhap {n} dong, moi dong: u k v1 v2 ... vk (dinh u co k con):")
    tree = [[] for _ in range(n + 1)]
    is_child = [False] * (n + 1)
    for _ in range(n):
        parts = list(map(int, input().split()))
        u, k, *children = parts
        if len(children) < k:
            children += list(map(int, input().split()))
        for v in children:
            tree[u].append(v)
            is_child[v] = True
    root = 1
    for i in range(1, n + 1):
        if not is_child[i]:
            root = i
    return n, tree, root

def dfs_height(u, tree, depth, depths, heights):
    depths[u] = depth
    max_child_height = -1
    for v in tree[u]:
        dfs_height(v, tree, depth + 1, depths, heights)
        max_child_height = max(max_child_height, heights[v])
    heights[u] = max_child_height + 1

def bottom_up(tree, root, n):
    depths = [0] * (n + 1)
    heights = [0] * (n + 1)
    dfs_height(root, tree, 0, depths, heights)
    nodes = []
    for u in range(1, n + 1):
        nodes.append((heights[u], depths[u], u))
    # Sắp xếp theo height tăng dần, depth tăng dần, u tăng dần
    nodes.sort()
    print("Duyet bottom-up (cac dinh theo thu tu khong giam cua chieu cao, cung chieu cao thi theo do sau, trai sang phai):")
    last_height = -1
    for h, d, u in nodes:
        if h != last_height:
            if last_height != -1:
                print()
            print(f"Chieu cao {h}: ", end='')
            last_height = h
        print(u, end=' ')
    print()

def main():
    n, tree, root = read_tree()
    bottom_up(tree, root, n)

if __name__ == "__main__":
    main()
