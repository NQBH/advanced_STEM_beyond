def amap_to_eal(amap_entries):
    # Vi AMap cung dang (u, v, w) nen chi can tra lai danh sach nay
    return amap_entries

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
k = int(input("Nhap so bo (u v w): "))

print("Nhap cac bo (u v w):")
amap_entries = []
for _ in range(k):
    u, v, w = map(int, input().split())
    amap_entries.append((u, v, w))

eal = amap_to_eal(amap_entries)

print("Danh sach ke mo rong (EAL):")
for u, v, w in eal:
    print(f"{u} {v} {w}")