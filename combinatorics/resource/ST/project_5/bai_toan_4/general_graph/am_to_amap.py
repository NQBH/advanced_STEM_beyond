def am_to_amap(matrix):
    n = len(matrix)
    amap = {}

    for u in range(n):
        for v in range(n):
            if matrix[u][v] == 1:
                if u not in amap:
                    amap[u] = {}
                amap[u][v] = 1  # Gan trong so la 1 (do do thi khong co trong so)

    return amap

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
print("Nhap ma tran ke (AM):")
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().split())))

amap = am_to_amap(matrix)

print("Adjacency Map (AMap):")
for u in amap:
    for v in amap[u]:
        print(f"{u} -> {v}: {amap[u][v]}")