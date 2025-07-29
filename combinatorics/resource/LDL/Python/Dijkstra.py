import heapq
from collections import defaultdict

# n: so dinh, m: so cap dinh co canh noi
n, m = map(int, input().split())

# adj[u] = danh sach cac cap (v, w) nghia la co canh tu u den v voi trong so w
adj = defaultdict(list)

# Nhap m dong, moi dong co: u, v, k (co k canh giua u va v), sau do k dong trong so
for _ in range(m):
    u, v, k = map(int, input().split())
    for _ in range(k):
        w = int(input())  # Nhap trong so w cua 1 canh tu u den v
        adj[u].append((v, w))
        adj[v].append((u, w))  # Do thi vo huong


# Thuat toan Dijkstra tim duong di ngan nhat tu dinh start
def dijkstra(start):
    dist = [float('inf')] * n  # dist[u]: khoang cach ngan nhat tu start den u
    dist[start] = 0

    heap = [(0, start)]  # Hang doi uu tien (khoang cach, dinh)

    while heap:
        d, u = heapq.heappop(heap)

        if d > dist[u]:
            continue  # Bo qua neu da co duong di ngan hon

        for v, w in adj[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heapq.heappush(heap, (dist[v], v))

    return dist


# Dijkstra tu dinh 0
start_node = 0
shortest_distances = dijkstra(start_node)

# In ra khoang cach ngan nhat tu dinh 0 den cac dinh con lai
print("Khoang cach ngan nhat tu dinh", start_node, ":")
for i, d in enumerate(shortest_distances):
    if d == float('inf'):
        print(f"Dinh {i}: khong the den")
    else:
        print(f"Dinh {i}: {d}")