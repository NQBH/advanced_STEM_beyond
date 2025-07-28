n = int(input("Nhap so dinh: "))
m = int(input("Nhap so canh: "))

# Khoi tao danh sach ke
adj_list = [[] for _ in range(n)]

print("Nhap danh sach ke mo rong (u v w):")
for _ in range(m):
    u, v, w = map(int, input().split())
    adj_list[u].append(v)  # Bo trong so, chi lay v

print("Danh sach ke (AL):")
for i in range(n):
    print(f"{i}:", *adj_list[i])