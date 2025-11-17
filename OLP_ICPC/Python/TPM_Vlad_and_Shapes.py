import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    a = []
    dem = 0
    k = 0
    for i in range(n):
        line = list(input())
        if '1' in line:
            a.append(line)
    for i in range(len(a)):
        if a[i].count('1') == a[i+1].count('1'):
            print('SQUARE')
            break
        else:
            print('TRIANGLE')
            break