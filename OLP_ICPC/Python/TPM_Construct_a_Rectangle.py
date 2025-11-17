import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))
    a.sort()
    if (a[0] + a[1] == a[2]) or ((a[1] == a[0] or a[1] == a[2]) and  ((sum(a) - 2*a[1]) % 2 == 0)):
        print('YES')
    else: print('NO')