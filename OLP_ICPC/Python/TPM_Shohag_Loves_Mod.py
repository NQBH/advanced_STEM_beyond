import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    for i in range(1,n*2,2):
        print(i, end=' ')
    print()