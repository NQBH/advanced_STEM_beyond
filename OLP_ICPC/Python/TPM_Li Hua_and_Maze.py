import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n,m = map(int, input().split())
    a = list(map(int, input().split()))
    b = 5
    if ((a[0] != 1) and (a[0] != n)) and ((a[1] != 1) and (a[1] != m)):
        b = min(b,4)
    elif (a[0] == a[1] == 1) or (a[0] == n and a[1] == m) or (a[0] == 1 and a[1] == m) or (a[0] == n and a[1] == 1):
        b = min(b,2)
    else:
        b = min(b,3)
    if ((a[2] != 1) and (a[2] != n)) and ((a[3] != 1) and (a[3] != m)):
        b = min(b,4)
    elif (a[2] == a[3] == 1) or (a[2] == n and a[3] == m) or (a[2] == 1 and a[3] == m) or (a[2] == n and a[3] == 1):
        b = min(b,2)
    else:
        b = min(b,3)
    print(b)