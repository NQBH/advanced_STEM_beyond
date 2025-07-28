# Ham chuyen AM sang EAL cho da do thi
def am_to_eal(matrix):
    n = len(matrix)
    eal = [[] for _ in range(n)]  # Tao danh sach ke rong cho n dinh

    for i in range(n):
        for j in range(n):
            weight = matrix[i][j]  # So canh tu i den j
            if weight > 0:
                eal[i].append((j, weight))  # Them (j, weight) vao danh sach

    return eal

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
print("Nhap ma tran ke:")
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

# Chuyen doi va in ket qua
eal = am_to_eal(matrix)
print("Danh sach ke mo rong (EAL):")
for i, neighbors in enumerate(eal):
    print(f"{i}: {neighbors}")