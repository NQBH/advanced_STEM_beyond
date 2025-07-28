# Ham chuyen ma tran ke sang adjacency map
def am_to_amap(matrix):
    n = len(matrix)
    amap = {}  # Khoi tao dict trong Python

    for i in range(n):
        for j in range(n):
            count = matrix[i][j]
            if count > 0:
                if i not in amap:
                    amap[i] = {}
                amap[i][j] = count  # Luu so canh tu i den j

    return amap

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
print("Nhap ma tran ke (cach nhau bang dau cach):")
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

# Chuyen doi va in ket qua
amap = am_to_amap(matrix)

print("Ban do ke (AMap):")
for u in amap:
    print(f"{u}: ", end="")
    for v, w in amap[u].items():
        print(f"({v},{w})", end=" ")
    print()