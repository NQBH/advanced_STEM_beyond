# Ham chuyen ban do ke sang ma tran ke
def amap_to_matrix(amap, n):
    matrix = [[0] * n for _ in range(n)]  # Khoi tao ma tran toan 0

    for i in amap:
        for j in amap[i]:
            matrix[i][j] = amap[i][j]  # Ghi trong so vao ma tran

    return matrix

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
amap = {}

print("Nhap ban do ke (dinh: (dinh,trongso)...):")
for _ in range(n):
    line = input()
    if ':' not in line:
        continue
    u_str, rest = line.split(':')
    u = int(u_str.strip())
    amap[u] = {}
    tokens = rest.strip().split()
    for token in tokens:
        v, w = map(int, token.strip("()").split(","))
        amap[u][v] = w

# Chuyen doi va in ma tran ke
matrix = amap_to_matrix(amap, n)

print("Ma tran ke:")
for row in matrix:
    print(" ".join(map(str, row)))