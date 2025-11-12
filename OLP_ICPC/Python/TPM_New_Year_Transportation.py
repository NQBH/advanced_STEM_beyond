import sys
input = lambda: sys.stdin.readline().strip()
import sys
input = lambda: sys.stdin.readline().strip()
n,t  =  map(int, input().split())
a = list(map(int, input().split()))
i = 1
while i < t: 
    if i + a[i-1] == t:
        i = -1
        print('YES')
        break
    else: 
        i += a[i-1]
if i > -1:
    print('NO')
    