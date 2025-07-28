def amap_to_al(n, amap_entries):
    # Khoi tao danh sach ke rong
    al = [[] for _ in range(n)]

    for u, v, w in amap_entries:
        al[u].extend([v] * w)  # Them v vao danh sach ke cua u w lan

    return al

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
k = int(input("Nhap so bo (u v w): "))

print("Nhap cac bo (u v w):")
amap_entries = []
for _ in range(k):
    u, v, w = map(int, input().split())
    amap_entries.append((u, v, w))

al = amap_to_al(n, amap_entries)

print("Danh sach ke (AL):")
for u in range(n):
    print(f"{u}: {' '.join(map(str, al[u]))}")