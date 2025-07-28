def amap_to_am(n, amap_entries):
    
    am = [[0 for _ in range(n)] for _ in range(n)]

    for u, v, w in amap_entries:
        am[u][v] = w  # Gan so luong canh tu u den v la w

    return am

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
k = int(input("Nhap so canh (bo u v w): "))

print("Nhap cac bo (u v w):")
amap_entries = []
for _ in range(k):
    u, v, w = map(int, input().split())
    amap_entries.append((u, v, w))

am = amap_to_am(n, amap_entries)

print("Ma tran ke (AM):")
for row in am:
    print(" ".join(map(str, row)))