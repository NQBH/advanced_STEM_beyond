t = int(input())
for _ in range(t):
    n,m,x,y = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    dem = 0
    if y >= a[len(a)-1]:
        dem += n
    else:
        for i in range(n):
            if  y >= a[i]:
                dem += 1
            else: break
    if x >= b[len(b)-1]:
        dem += m
    else:
        for j in range(m):
            if x >= b[j]: 
                dem += 1
            else: break
    print(dem)