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

def top_down(tree, root):
    from collections import deque
    q = deque()
    q.append((root, 0))
    current_depth = 0
    print("Duyet top-down (cac dinh theo thu tu khong giam cua do sau, trai sang phai):")
    while q:
        sz = len(q)
        level_nodes = []
        for _ in range(sz):
            u, depth = q.popleft()
            level_nodes.append(u)
            for v in tree[u]:
                q.append((v, depth + 1))
        print(f"Do sau {current_depth}: ", end='')
        for u in level_nodes:
            print(u, end=' ')
        print()
        current_depth += 1

def main():
    n, tree, root = read_tree()
    top_down(tree, root)

if __name__ == "__main__":
    main()
