import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    a = []
    for k in range(1, len(str(n))+1):
        d = 1 + 10**k
        if n % d == 0:
            x = n // d
            a.append(x)
    if len(a) > 0:
        a.sort()
        print(len(a))
        for i in a:
            print(i,end=' ')
        print()
    else:
        print(0)