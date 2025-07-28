# Chuyen ma tran ke da do thi sang danh sach ke
def am_to_al(matrix):
    n = len(matrix)
    al = [[] for _ in range(n)]  # Khoi tao danh sach ke rong

    for i in range(n):
        for j in range(n):
            count = matrix[i][j]  # So luong canh tu i den j
            al[i].extend([j] * count)  # Them j vao nho count lan

    return al

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
print("Nhap ma tran ke (moi dong cach nhau boi khoang trang):")
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

# Chuyen doi va in ket qua
al = am_to_al(matrix)
print("Danh sach ke (AL):")
for i, neighbors in enumerate(al):
    print(f"{i}: {neighbors}")