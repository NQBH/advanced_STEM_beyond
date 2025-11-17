import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t): 
    a,b = map(int, input().split())
    if a + b == 3:
        print('NO')
    elif ((a % 2 == 0) and (a / 2 != b)) or ((b % 2 == 0) and (b / 2 != a)):
        print('YES')
    else: print('NO')