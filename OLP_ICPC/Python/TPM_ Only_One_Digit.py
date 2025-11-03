import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    num = int(input())
    lst = [int(i) for i in str(num)]
    print(min(lst))