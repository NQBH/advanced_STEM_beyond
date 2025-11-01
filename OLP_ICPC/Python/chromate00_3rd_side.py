t = int(input())
for _ in range(t):
    n = int(input())
    sm = sum(map(int, input().split()))
    print(sm - n + 1)