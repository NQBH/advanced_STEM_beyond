import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    for i in range(n-1):
        for j in range(i+1,n):
            b.append(a[j] - a[i])
    print(len(set(b)))