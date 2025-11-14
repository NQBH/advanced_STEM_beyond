import sys
input = lambda: sys.stdin.readline().strip()
n = int(input())
a = list(map(int, input().split()))

day_max = 0
dem = 1
i = 1

if len(set(a)) == 1:
    print(1)
else:
    while i <= n-1:
        if a[i] > a[i-1]:
            i += 1
            dem += 1
        else: 
            day_max = max(day_max,dem)
            dem = 1     
            i += 1
    print(max(day_max,dem))