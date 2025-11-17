import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    a,b,c,d = map(int, input().split())
    if (a == c) and (d == b):
        print(0)
    elif (b == d) and (a > c):
        print(abs(a-c))
    else: 
        if (d - b) and (a + (d-b) >= c) and (d >= b):
            print(d - b + (a + (d-b) -c))
        else: print(-1)