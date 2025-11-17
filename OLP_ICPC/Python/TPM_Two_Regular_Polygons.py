import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n,m = map(int, input().split())
    if n % m == 0:
        print('YES')
    else: print('NO')