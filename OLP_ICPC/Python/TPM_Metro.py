import sys
input = lambda: sys.stdin.readline().strip()
n,s = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if (a[0] != 0) and (a[s-1] == 1):
    print('YES')
elif (a[0] != 0) and (b[s-1] == 1):
    for  i in range(s-1, n):
        if b[i] == a[i] == 1:
            print('YES')
            break
    else: 
        print('NO')
else: print('NO')