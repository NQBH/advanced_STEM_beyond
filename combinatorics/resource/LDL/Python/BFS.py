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
def bfs(start):
    visited = [False] * n
    queue = deque()
    order = []

    visited[start] = True
    queue.append(start)

    while queue:
        u = queue.popleft()
        order.append(u)
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                queue.append(v)
    return order

# Thuc hien BFS tu dinh 0
start_node = 0
result = bfs(start_node)
print(*result)