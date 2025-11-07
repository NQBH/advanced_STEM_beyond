import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    print('1' + (n-1)*'0')