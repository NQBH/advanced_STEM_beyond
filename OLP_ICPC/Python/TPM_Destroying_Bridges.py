import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    # a = (n*(n-1))/2  # so cau 
    if  k >= (n-1): 
        print(1)
    else: 
        print(n)