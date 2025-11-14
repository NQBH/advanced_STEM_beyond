import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    vitri = 0
    so = 0
    dem = 0
    for i in range(n): 
        vitri == i
        if  a[i] % 2 == 0:
            print(1)
            print(i + 1)
            break
        else: 
            dem += a[i]
            so += 1
            if dem % 2 == 0:
                print(so)
                b = list(x for x in range(vitri,vitri + so))
                for i in range(len(b)):
                    print(b[i]+1,end=' ')
                break
    else:
        print(-1)