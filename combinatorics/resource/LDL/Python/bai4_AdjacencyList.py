from collections import defaultdict

# Nhap danh sach ke
n = int(input("Nhap so dinh n: "))
adj_list = defaultdict(list)
print("Nhap danh sach ke (nhap xong moi dinh thi Enter):")

for u in range(n):
    row = input(f"{u}: ").strip()
    if row:
        adj_list[u] = list(map(int, row.split()))

adj_matrix = [[0]*n for _ in range(n)]
edge_list = []
adj_map = defaultdict(lambda: (defaultdict(list), defaultdict(list)))

for u in range(n):
    for v in adj_list[u]:
        adj_matrix[u][v] += 1
        # Chi luu danh sach canh khi dem duoc so canh sau
        # Tam dem sau de tranh trung lap khi convert
for u in range(n):
    for v in set(adj_list[u]):
        k = adj_list[u].count(v)
        edge_list.append((u, v, k))
        for _ in range(k):
            adj_map[u][1][v].append((u, v))  # Outgoing
            adj_map[v][0][u].append((u, v))  # Incoming

# In ma tran ke
print("\n============Ma tran ke:")
for row in adj_matrix:
    print(' '.join(map(str, row)))

# In danh sach canh
print("\n============Edge List:")
for u, v, k in edge_list:
    print(f"{u} {v} {k}")

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