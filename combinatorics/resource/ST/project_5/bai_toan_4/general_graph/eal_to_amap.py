n = int(input("Nhap so dinh: "))
m = int(input("Nhap so canh: "))

# Khoi tao AMap: su dung dictionary
adj_map = {}

print("Nhap danh sach ke mo rong (u v w):")
for _ in range(m):
    u, v, w = map(int, input().split())
    if u not in adj_map:
        adj_map[u] = []
    adj_map[u].append((v, w))  # Them (v, w) vao danh sach cua u

print("Adjacency Map (AMap):")
for u in range(n):
    print(f"{u}:", adj_map.get(u, []))  # Neu khong co dinh u thi tra ve []