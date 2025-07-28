# Ham chuyen Adjacency Map sang Extended Adjacency List
def amap_to_eal(amap, n):
    eal = [[] for _ in range(n)]  # Khoi tao danh sach rong cho n dinh
    for u in amap:
        for v, w in amap[u].items():  # Duyet qua cac dinh ke cua u
            eal[u].append((v, w))     # Them cap (v, w) vao EAL[u]
    return eal

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
amap = {}

print("Nhap ban do ke (dinh: (dinh,trongso)...):")
# Vi du: 0: (1,3) (2,5)
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

# Chuyen doi va in ket qua
eal = amap_to_eal(amap, n)

print("Danh sach ke mo rong (EAL):")
for i, neighbors in enumerate(eal):
    print(f"{i}: {neighbors}")