import heapq

def input_graph():
    n = int(input("Nhap so dinh: "))
    m = int(input("Nhap so canh: "))
    adj = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input("Nhap canh u v w: ").split())
        adj[u].append((v, w))
        adj[v].append((u, w))  # do thi don vo huong
    s = int(input("Nhap dinh bat dau: "))
    return n, adj, s

def dijkstra(n, adj, s):
    dist = [float('inf')] * n
    dist[s] = 0
    pq = [(0, s)]  # (khoang cach, dinh)
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, w in adj[u]:
            if dist[v] > d + w:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))
    return dist

if __name__ == "__main__":
    n, adj, s = input_graph()
    dist = dijkstra(n, adj, s)
    for i in range(n):
        print(f"Khoang cach tu {s} den {i}: {dist[i]}")