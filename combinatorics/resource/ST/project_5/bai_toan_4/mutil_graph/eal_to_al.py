def eal_to_al(n, eal):
    # Khoi tao danh sach ke rong
    al = [[] for _ in range(n)]

    for u, v, w in eal:
        al[u].extend([v] * w)  # Them v vao al[u] w lan

    return al

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
k = int(input("Nhap so bo (u v w): "))

eal = []
print("Nhap cac bo (u v w):")
for _ in range(k):
    u, v, w = map(int, input().split())
    eal.append((u, v, w))

al = eal_to_al(n, eal)

print("Danh sach ke (AL):")
for u in range(n):
    print(f"{u}: {' '.join(map(str, al[u]))}")