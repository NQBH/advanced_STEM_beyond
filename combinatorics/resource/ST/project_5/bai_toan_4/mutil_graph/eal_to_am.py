# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
m = int(input("Nhap so canh: "))

# Khoi tao ma tran ke n x n voi gia tri 0
am = [[0 for _ in range(n)] for _ in range(n)]

print("Nhap danh sach ke mo rong (u v w):")
for _ in range(m):
    u, v, w = map(int, input().split())
    am[u][v] = w  # Gan so canh tu u den v

# In ma tran ke
print("Ma tran ke (AM):")
for row in am:
    print(" ".join(map(str, row)))