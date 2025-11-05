import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    num = s.count('0')
    dem = 0
    for i in range(num):
        if s[i] == '1':
            dem += 1
    print(dem)