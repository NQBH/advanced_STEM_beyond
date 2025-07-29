from collections import defaultdict

# Nhap ma tran ke (do thi co huong)
n = int(input("Nhap so dinh n: "))
print("Nhap ma tran ke:")
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

# Adjacency List
adj_list = defaultdict(list)

# Edge List
edge_list = []

# Adjacency Map: moi dinh se map toi (incoming, outgoing)
adj_map = defaultdict(lambda: (defaultdict(list), defaultdict(list)))

for i in range(n):
    for j in range(n):
        k = matrix[i][j]  # So canh tu i den j
        if k > 0:
            adj_list[i].extend([j] * k)        # Them j vao danh sach ke cua i, lap k lan
            edge_list.append((i, j, k))        # Them (i, j, k): tu i den j co k canh

            for _ in range(k):
                adj_map[i][1][j].append((i, j))  # Outgoing tu i den j
                adj_map[j][0][i].append((i, j))  # Incoming den j tu i

# In danh sach ke
print("\n============Adjacency List:")
for u in range(n):
    print(f"{u}: {adj_list[u]}")

# In danh sach canh
print("\n============Edge List:")
for u, v, k in edge_list:
    print(f"{u} {v} {k}")

# In Adjacency Map
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