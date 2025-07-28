from collections import defaultdict

def al_to_amap(adj_list):
    amap = defaultdict(lambda: defaultdict(int))  # Khoi tao dict 2 chieu

    for u, neighbors in enumerate(adj_list):
        for v in neighbors:
            amap[u][v] += 1  # Tang so lan xuat hien cua canh (u,v)

    return amap

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
adj_list = []

print("Nhap danh sach ke:")
for i in range(n):
    row = list(map(int, input(f"Ke cua dinh {i}: ").split()))
    adj_list.append(row)

# Chuyen doi va in ket qua
amap = al_to_amap(adj_list)

print("Ban do ke (AMap):")
for u in amap:
    print(f"{u}: ", end="")
    for v, w in amap[u].items():
        print(f"({v},{w})", end=" ")
    print()