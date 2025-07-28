# Ham chuyen tu danh sach ke mo rong ve danh sach ke
def eal_to_al(eal, n):
    al = [[] for _ in range(n)]  # Khoi tao danh sach ke rong

    for i in range(n):
        for (j, _) in eal[i]:  # Bo qua trong so, chi lay dinh j
            al[i].append(j)

    return al

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

# Chuyen doi va in ra danh sach ke
al = eal_to_al(eal, n)

print("Danh sach ke (AL):")
for i, neighbors in enumerate(al):
    print(f"{i}: {neighbors}")