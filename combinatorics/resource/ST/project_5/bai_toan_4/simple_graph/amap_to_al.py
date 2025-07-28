# Ham chuyen ban do ke sang danh sach ke
def amap_to_al(amap, n):
    al = [[] for _ in range(n)]  # Khoi tao danh sach ke

    for i in amap:
        for j in amap[i]:
            al[i].append(j)  # Bo qua trong so, chi lay dinh ke

    return al

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

# Chuyen doi va in danh sach ke
al = amap_to_al(amap, n)

print("Danh sach ke (AL):")
for i, neighbors in enumerate(al):
    print(f"{i}: {neighbors}")