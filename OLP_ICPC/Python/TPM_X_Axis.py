import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))
    a.sort()
    print(abs(a[1]-a[0]) + abs(a[1] - a[2]))