def am_to_eal(matrix):
    n = len(matrix)
    eal = []

    for u in range(n):
        for v in range(n):
            if matrix[u][v] == 1:
                eal.append((u, v, 1))  # Them canh (u, v) vao danh sach voi trong so 1

    return eal

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
print("Nhap ma tran ke (AM):")
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

eal = am_to_eal(matrix)

print("Danh sach ke mo rong (EAL):")
for u, v, w in eal:
    print(f"{u} {v} {w}")