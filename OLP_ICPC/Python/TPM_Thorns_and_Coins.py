import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    a = input()
    dem = 0
    for i in range(n):
        if (i > 1) and (a[i-1] == a[i-2] == '*'):
            break
        elif (a[i] == '@'):
            dem += 1
    print(dem)