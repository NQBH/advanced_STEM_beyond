def am_to_al(matrix):
    n = len(matrix)
    al = [[] for _ in range(n)]  # Khoi tao danh sach ke

    for u in range(n):
        for v in range(n):
            if matrix[u][v] == 1:  # Neu co canh tu u den v
                al[u].append(v)   # Them v vao danh sach cua u

    return al

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
print("Nhap ma tran ke (AM):")
am = []
for _ in range(n):
    row = list(map(int, input().split()))
    am.append(row)

al = am_to_al(am)

print("Danh sach ke (AL):")
for u in range(n):
    print(f"{u}: {' '.join(map(str, al[u]))}")