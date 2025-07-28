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

def postorder(u, tree):
    # Duyệt tất cả các con trước
    for v in tree[u]:
        postorder(v, tree)
    # Sau khi duyệt xong các con, thăm u
    print(u, end=' ')

def main():
    n, tree, root = read_tree()
    print("Thu tu duyet postorder:", end=' ')
    postorder(root, tree)
    print()

if __name__ == "__main__":
    main()
