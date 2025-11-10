import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    a = list(map(int, input().split()))
    dem  = 0
    total = 0
    for i in a:
        if (total > 0) and (i == 0):
            dem += 1
            total -= 1
        if (i != 0) and (i >= k):
            total += i
    print(dem) 