# Ham chuyen danh sach ke mo rong sang ban do ke
def eal_to_amap(eal, n):
    amap = {}  # Tao tu dien rong

    for i in range(n):
        amap[i] = {}  # Khoi tao tu dien con cho moi dinh
        for (j, w) in eal[i]:  # Duyet cac canh ke
            amap[i][j] = w  # Gan trong so vao dinh ke

    return amap

# Nhap du lieu tu ban phim
n = int(input("Nhap so dinh: "))
eal = []

print("Nhap danh sach ke mo rong:")
for i in range(n):
    line = input(f"Dinh {i} (dinh,trongso cach nhau boi space): ")
    pairs = []
    if line.strip() != "":
        tokens = line.split()
        for token in tokens:
            u, w = map(int, token.strip("()").split(","))
            pairs.append((u, w))
    eal.append(pairs)

# Chuyen doi va in ban do ke
amap = eal_to_amap(eal, n)

print("Ban do ke (AMap):")
for u in amap:
    print(f"{u}: {amap[u]}")