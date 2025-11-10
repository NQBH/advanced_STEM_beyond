import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    if ((n + 1) // 2 - (n - k + 1) // 2) % 2 == 0:
        print('YES')
    else: 
      print('NO')  