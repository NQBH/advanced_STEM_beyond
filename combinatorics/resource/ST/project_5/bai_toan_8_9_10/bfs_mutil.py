from collections import deque

# Nhap da do thi tu ban phim
def input_multigraph():
    n = int(input("Nhap so dinh: "))
    m = int(input("Nhap so canh: "))
    adj = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input("Nhap canh u v (co the trung): ").split())
        adj[u].append(v)
        adj[v].append(u)  # Do thi vo huong co the trung canh
    return n, adj

# BFS co xu ly trung canh
def bfs_multigraph(start, adj, n):
    visited = [False] * n
    queue = deque([start])
    visited[start] = True
    print("Thu tu duyet:", end=" ")
    while queue:
        u = queue.popleft()
        print(u, end=" ")
        for v in adj[u]:
            if not visited[v]:  # Chi dua vao hang doi neu chua tham
                visited[v] = True
                queue.append(v)

# Main
if __name__ == "__main__":
    n, adj = input_multigraph()
    s = int(input("Nhap dinh bat dau: "))
    bfs_multigraph(s, adj, n)