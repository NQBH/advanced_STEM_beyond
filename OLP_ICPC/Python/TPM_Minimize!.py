import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    a,b = map(int, input().split())
    total =  0
    c = 10**19
    for i in range(a,b+1):
        total = (i - a) + (b - i)
        c = min(total,c)
    print(c)