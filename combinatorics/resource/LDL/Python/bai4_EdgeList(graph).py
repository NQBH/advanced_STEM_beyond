from collections import defaultdict

# Nhap danh sach canh (do thi co huong)
n, m = map(int, input("Nhap so dinh va so cap dinh co canh noi (n m): ").split())
print("Nhap m dong: u v k (co k canh tu u den v):")
edge_list = []
for _ in range(m):
    u, v, k = map(int, input().split())
    edge_list.append((u, v, k))

# Tao danh sach ke
adj_list = defaultdict(list)

# Tao ma tran ke (ban dau la 0 het)
adj_matrix = [[0] * n for _ in range(n)]

# Tao adjacency map: moi dinh map toi (incoming, outgoing)
adj_map = defaultdict(lambda: (defaultdict(list), defaultdict(list)))

# Xu ly edge list
for u, v, k in edge_list:
    # Cap nhat danh sach ke
    adj_list[u].extend([v] * k)

    # Cap nhat ma tran ke
    adj_matrix[u][v] += k

    # Cap nhat adjacency map
    for _ in range(k):
        adj_map[u][1][v].append((u, v))  # Outgoing tu u den v
        adj_map[v][0][u].append((u, v))  # Incoming den v tu u

# In danh sach ke
print("\n============Adjacency List:")
for u in range(n):
    print(f"{u}: {adj_list[u]}")

# In ma tran ke
print("\n============Adjacency Matrix:")
for row in adj_matrix:
    print(" ".join(map(str, row)))

# In adjacency map
print("\n============Adjacency Map:")
for v in range(n):
    incoming, outgoing = adj_map[v][0], adj_map[v][1]
    print(f"Dinh {v}:")
    print("  Incoming:")
    for u in incoming:
        print(f"    {u}: {incoming[u]}")
    print("  Outgoing:")
    for w in outgoing:
        print(f"    {w}: {outgoing[w]}")