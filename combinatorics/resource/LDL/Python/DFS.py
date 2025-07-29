from collections import deque, defaultdict

# n: so dinh, m: so cap dinh noi voi nhau
n, m = map(int, input().split())

# key: int (dinh), value: list[int] (danh sach dinh ke)
adj = defaultdict(list)

for _ in range(m):
    u, v, k = map(int, input().split())
    # Them k lan canh tu u den v
    for _ in range(k):
        adj[u].append(v)
        adj[v].append(u) # Do thi vo huong
def dfs(u, visited, order):
    visited[u] = True
    order.append(u)
    for v in adj[u]:
        if not visited[v]:
            dfs(v, visited, order)

# Thuc hien DFS tu dinh 0
visited = [False] * n
order = []
dfs(0, visited, order)
print(*order)