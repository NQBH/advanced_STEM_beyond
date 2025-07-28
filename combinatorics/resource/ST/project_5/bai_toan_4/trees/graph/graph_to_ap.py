def dfs(u, p, adj, parent):
    parent[u] = p  # Gan cha cua u la p
    for v in adj[u]:
        if v != p:
            dfs(v, u, adj, parent)

n = int(input("Nhap so dinh: "))
adj = [[] for _ in range(n)]

print("Nhap danh sach ke:")
for i in range(n):
    line = list(map(int, input(f"{i}: ").split()))
    adj[i].extend(line)

parent = [-1] * n
dfs(0, -1, adj, parent)  # Goc la 0

print("Mang parent:")
print(parent)