def dfs(u, fc, ns, visited, adj):
    visited[u] = True
    if fc[u] != -1:
        v = fc[u]
        adj[u].append(v)
        adj[v].append(u)
        dfs(v, fc, ns, visited, adj)
    if ns[u] != -1:
        v = ns[u]
        adj[u].append(v)
        adj[v].append(u)
        dfs(v, fc, ns, visited, adj)

n = int(input("Nhap so nut: "))
print("Nhap mang fc:")
fc = list(map(int, input().split()))
print("Nhap mang ns:")
ns = list(map(int, input().split()))

adj = [[] for _ in range(n)]
visited = [False] * n

dfs(0, fc, ns, visited, adj)

print("Danh sach ke (Graph):")
for i in range(n):
    print(f"{i}:", adj[i])