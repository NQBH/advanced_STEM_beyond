import sys
input = lambda: sys.stdin.readline().strip()
n, m = map(int, input().split())
a = list(map(int, input().split()))
prefix_thuan = [0] * n
for i in range(1, n):
    prefix_thuan[i] = prefix_thuan[i-1]
    if a[i-1] > a[i]:
        prefix_thuan[i] += a[i-1] - a[i]
prefix_nghich = [0] * n
for i in range(n-2, -1, -1):
    prefix_nghich[i] = prefix_nghich[i+1]
    if a[i+1] > a[i]:
        prefix_nghich[i] += a[i+1] - a[i]
for _ in range(m):
    s, t = map(int, input().split())
    if s < t:
        print(prefix_thuan[t-1] - prefix_thuan[s-1])
    else:
        print(prefix_nghich[t-1] - prefix_nghich[s-1])