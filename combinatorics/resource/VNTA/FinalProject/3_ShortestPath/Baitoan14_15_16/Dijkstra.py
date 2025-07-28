import heapq

INF = float('inf')

def inp():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = input().split()
        u, v, w = int(u), int(v), float(w)
        graph[u].append((v, w))
        graph[v].append((u, w))  # đồ thị vô hướng
    return graph, n, m

def find_path(target, prev):
    path = []
    while target != -1:
        path.append(target)
        target = prev[target]
    path.reverse()
    return path

def dijkstra_trad(source, graph):
    n = len(graph)
    dist = [INF] * n
    prev = [-1] * n
    visited = [False] * n
    dist[source] = 0
    Q = list(range(n))

    while Q:
        u = -1
        for v in Q:
            if not visited[v] and (u == -1 or dist[v] < dist[u]):
                u = v
        if u == -1:
            break
        visited[u] = True
        Q.remove(u)

        for v, w in graph[u]:
            if visited[v]:
                continue
            alt = dist[u] + w
            if alt < dist[v]:
                dist[v] = alt
                prev[v] = u
    return dist, prev

def dijkstra_pq(source, graph):
    n = len(graph)
    dist = [INF] * n
    prev = [-1] * n
    dist[source] = 0
    pq = [(0, source)]

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in graph[u]:
            alt = dist[u] + w
            if alt < dist[v]:
                dist[v] = alt
                prev[v] = u
                heapq.heappush(pq, (alt, v))
    return dist, prev

graph, n, m = inp()
source = int(input())

print("=== Traditional Dijkstra ===")
dist, prev = dijkstra_trad(source, graph)
for v in range(n):
    print(f"{v}: ", end='')
    if dist[v] == INF:
        print("Không có đường đi")
    else:
        print(f"Khoảng cách = {dist[v]:.2f}; Đường đi: ", end='')
        path = find_path(v, prev)
        print(" ".join(map(str, path)))

print("\n=== Priority Queue Dijkstra ===")
dist2, prev2 = dijkstra_pq(source, graph)
for v in range(n):
    print(f"{v}: ", end='')
    if dist2[v] == INF:
        print("Không có đường đi")
    else:
        print(f"Khoảng cách = {dist2[v]:.2f}; Đường đi: ", end='')
        path = find_path(v, prev2)
        print(" ".join(map(str, path)))