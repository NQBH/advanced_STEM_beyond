def build_fcns(u, p, adj, fc, ns):
    children = [v for v in adj[u] if v != p]
    if children:
        fc[u] = children[0]
        for i in range(len(children) - 1):
            ns[children[i]] = children[i + 1]
    for v in children:
        build_fcns(v, u, adj, fc, ns)

n = int(input("Nhap so dinh: "))
adj = [[] for _ in range(n)]

print("Nhap danh sach ke:")
for i in range(n):
    line = list(map(int, input(f"{i}: ").split()))
    adj[i].extend(line)

fc = [-1] * n
ns = [-1] * n

build_fcns(0, -1, adj, fc, ns)

print("Mang fc:", fc)
print("Mang ns:", ns)