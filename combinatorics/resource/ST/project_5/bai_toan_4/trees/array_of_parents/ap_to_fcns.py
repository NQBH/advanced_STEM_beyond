def ap_to_fcns(parent):
    n = len(parent)
    fc = [-1] * n  # Mang first child
    ns = [-1] * n  # Mang next sibling
    children = [[] for _ in range(n)]

    # Xay dung danh sach con cho moi nut
    for i in range(n):
        if parent[i] != -1:
            children[parent[i]].append(i)

    # Duyet moi nut, gan fc va ns
    for u in range(n):
        if children[u]:
            fc[u] = children[u][0]
            for i in range(len(children[u]) - 1):
                ns[children[u][i]] = children[u][i+1]

    return fc, ns

# Nhap du lieu
n = int(input("Nhap so nut: "))
print("Nhap mang parent (cach nhau boi dau cach):")
parent = list(map(int, input().split()))

fc, ns = ap_to_fcns(parent)

print("First Child (fc):", fc)
print("Next Sibling (ns):", ns)