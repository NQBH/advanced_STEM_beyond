import heapq

# Ham Dijkstra tren do thi tong quat
def dijkstra(n, edges, start):
    graph = [[] for _ in range(n)]  # Danh sach ke voi trong so

    # Xay dung do thi
    for u, v, w in edges:
        graph[u].append((v, w))  # Do thi co huong
        # graph[v].append((u, w))  # Neu do thi vo huong

    dist = [float('inf')] * n     # Khoang cach ban dau la vo cung
    dist[start] = 0               # Khoang cach tu start den chinh no = 0

    pq = [(0, start)]             # Hang doi uu tien voi (khoang cach, dinh)

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]: continue  # Neu da co duong ngan hon thi bo qua

        for v, w in graph[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))

    return dist

# Nhap du lieu
n = int(input("Nhap so dinh: "))
m = int(input("Nhap so canh: "))
edges = []
print("Nhap cac canh u v w:")
for _ in range(m):
    u, v, w = map(int, input().split())
    edges.append((u, v, w))

s = int(input("Nhap dinh bat dau: "))
res = dijkstra(n, edges, s)

print("Khoang cach ngan nhat tu dinh", s)
for i, d in enumerate(res):
    print(f"{s} -> {i}: {d}")