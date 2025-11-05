import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
k = 0
for _ in range(t):
    s,n = map(str, input().split())
    if s == 'P':
        k += int(n)
    else: 
        if int(n) - k >= 1:
            print('YES')
            k = 0
        else: 
            print('NO')
            k = abs(int(n) - k)