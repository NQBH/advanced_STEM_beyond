n = int(input("Nhap so dinh: "))
num_keys = int(input("Nhap so dinh co trong AMap: "))

eal = []  # Danh sach canh (Edge Array List)

print("Nhap AMap (u, so dinh ke, cac cap v w):")
for _ in range(num_keys):
    parts = input().split()
    u = int(parts[0])
    k = int(parts[1])
    for i in range(k):
        v = int(parts[2 + 2 * i])
        w = int(parts[3 + 2 * i])
        eal.append((u, v, w))  # Them canh (u, v, w) vao danh sach

# In danh sach canh
print("Danh sach canh (EAL):")
for edge in eal:
    print(edge)