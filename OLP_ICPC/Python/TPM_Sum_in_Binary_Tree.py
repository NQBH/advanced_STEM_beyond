import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    sum = 1
    while n > 1:
        sum += n
        n //= 2
    print(sum)