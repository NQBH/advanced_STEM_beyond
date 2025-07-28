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

def dfs(u, adj, visited):
    visited[u] = True
    print(u, end=" ")
    for v in adj[u]:
        if not visited[v]:
            dfs(v, adj, visited)

if __name__ == "__main__":
    n, adj = input_graph()
    visited = [False] * n
    s = int(input("Nhap dinh bat dau: "))
    print("Thu tu duyet:")
    dfs(s, adj, visited)