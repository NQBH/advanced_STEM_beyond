from collections import defaultdict

# Moi dinh se map toi (incoming, outgoing)
adj_map = defaultdict(lambda: (defaultdict(list), defaultdict(list)))

# Nhap so dinh
n = int(input("Nhap so dinh n: "))

# Nhap incoming edges
print("Nhap canh incoming theo dang: to_dinh from_dinh")
print("Nhap x khi ket thuc")
while True:
    s = input("Incoming: ")
    if s.strip().lower() == 'x':
        break
    v, u = map(int, s.split())
    adj_map[v][0][u].append((u, v))  # incoming cua v tu u
    adj_map[u][1][v].append((u, v))  # dong thoi cap nhat outgoing cua u toi v

# Danh sach canh
edge_list = []
for u in range(n):
    outgoing = adj_map[u][1]
    for v in outgoing:
        k = len(outgoing[v])
        if k > 0:
            edge_list.append((u, v, k))

# Danh sach ke
adj_list = defaultdict(list)
for u, v, k in edge_list:
    adj_list[u].extend([v] * k)

# Ma tran ke
adj_matrix = [[0]*n for _ in range(n)]
for u, v, k in edge_list:
    adj_matrix[u][v] = k

# In danh sach canh
print("\n============Edge List:")
for u, v, k in edge_list:
    print(f"{u} {v} {k}")

# In danh sach ke
print("\n============Adjacency List:")
for u in range(n):
    print(f"{u}: {adj_list[u]}")

# In ma tran ke
print("\n============Ma tran ke:")
for row in adj_matrix:
    print(' '.join(map(str, row)))