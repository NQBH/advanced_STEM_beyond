from collections import deque

# Ham nhap do thi tu ban phim
def input_graph():
    n = int(input("Nhap so dinh: "))  # So dinh
    m = int(input("Nhap so canh: "))  # So canh
    adj = [[] for _ in range(n)]      # Danh sach ke
    for _ in range(m):
        u, v = map(int, input("Nhap canh u v: ").split())
        adj[u].append(v)
        adj[v].append(u)              # Do thi vo huong
    return n, adj

# Ham BFS
def bfs(start, adj, n):
    visited = [False] * n            # Mang danh dau da tham chua
    queue = deque([start])           # Hang doi
    visited[start] = True
    print("Thu tu duyet:", end=' ')
    while queue:
        u = queue.popleft()          # Lay dinh tu hang doi
        print(u, end=' ')            # In ra dinh dang duyet
        for v in adj[u]:
            if not visited[v]:       # Neu chua tham thi dua vao hang doi
                visited[v] = True
                queue.append(v)

# Chuong trinh chinh
if __name__ == "__main__":
    n, adj = input_graph()
    s = int(input("Nhap dinh bat dau: "))
    bfs(s, adj, n)