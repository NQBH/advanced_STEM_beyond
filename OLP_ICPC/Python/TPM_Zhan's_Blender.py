import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())  # so qua
    x,y = map(int, input().split())  # so qua may xli , so qua 1s
    if (x >= y):
        if (n % y  == 0): print(int(n / y))
        else: print(int(n // y +1))
    else:
        if (n % x  == 0): print(int(n / x))
        else: print(int(n // x +1))


# 2
# 3
# 2
# 34
# 3