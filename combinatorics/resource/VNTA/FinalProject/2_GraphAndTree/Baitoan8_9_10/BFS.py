from collections import deque

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
visited = [False] * (n+1)

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)  # đồ thị vô hướng

def bfs(start):
    q = deque([start])
    visited[start] = True
    while q:
        u = q.popleft()
        print(u, end=' ')
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                q.append(v)

c = 0
for u in range(1, n+1):
    if not visited[u]:
        c += 1
        print(f'Thanh phan lien thong {c}: ', end='')
        bfs(u)
        print()