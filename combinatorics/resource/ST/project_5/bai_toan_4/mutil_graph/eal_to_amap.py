from collections import defaultdict

def eal_to_amap(eal):
    # Khoi tao ban do ke 2 chieu voi gia tri mac dinh la 0
    amap = defaultdict(lambda: defaultdict(int))

    for u, v, w in eal:
        amap[u][v] = w  # Gan so canh tu u den v la w

    return amap

# Nhap tu ban phim
n = int(input("Nhap so dinh: "))
k = int(input("Nhap so bo (u v w): "))

eal = []
print("Nhap cac bo (u v w):")
for _ in range(k):
    u, v, w = map(int, input().split())
    eal.append((u, v, w))

amap = eal_to_amap(eal)

print("Ban do ke (AMap):")
for u in range(n):
    print(f"{u}:", end=" ")
    for v in amap[u]:
        print(f"({v},{amap[u][v]})", end=" ")
    print()