from collections import deque

def input_graph():
    n = int(input("Nhap so dinh: "))
    m = int(input("Nhap so canh: "))
    directed = input("Do thi co huong? (y/n): ").strip().lower() == 'y'
    adj = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input("Nhap canh u v: ").split())
        adj[u].append(v)
        if not directed:
            adj[v].append(u)
    return n, adj

def bfs_general(start, adj, n):
    visited = [False] * n
    queue = deque([start])
    visited[start] = True
    print("Thu tu duyet:", end=" ")
    while queue:
        u = queue.popleft()
        print(u, end=" ")
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                queue.append(v)

if __name__ == "__main__":
    n, adj = input_graph()
    s = int(input("Nhap dinh bat dau: "))
    bfs_general(s, adj, n)