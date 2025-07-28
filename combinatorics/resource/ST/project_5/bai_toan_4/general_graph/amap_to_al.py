n = int(input("Nhap so dinh: "))
num_keys = int(input("Nhap so dinh co trong AMap: "))

# Khoi tao danh sach ke voi n danh sach con
adj_list = [[] for _ in range(n)]

print("Nhap AMap (u, so dinh ke, cac cap v w):")
for _ in range(num_keys):
    parts = input().split()
    u = int(parts[0])
    k = int(parts[1])
    for i in range(k):
        v = int(parts[2 + 2 * i])
        # Bo qua trong so w = parts[3 + 2 * i]
        adj_list[u].append(v)

# In danh sach ke
print("Danh sach ke (AL):")
for u in range(n):
    print(f"{u}:", adj_list[u])