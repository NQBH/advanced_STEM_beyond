t = int(input())
for _ in range(t):
    n = int(input())
    for j in range(n):
        d,s = map(int, input().split())
        k = (d - 1) + ((s + 1) // 2)
        if j == 0:
            dem_k = k
        if (j > 0) and (dem_k > d):
            if k < dem_k:
                dem_k = k
    print(int(dem_k))