import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    total  = 0
    for i in range(n):
        if (i % 2 == 0):
            total += a[i]
        else: 
            total -= a[i]
    print(total)