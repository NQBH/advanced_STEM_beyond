import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    a = list(map(int, input().split()))
    a.sort()
    print(int(((a[2] - a[0])**2 + a[1] ** 2) ** 0.5))