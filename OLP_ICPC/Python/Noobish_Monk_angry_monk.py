for _ in range(int(input())):
    n,k = map(int,input().split())
    mx = max(map(int, input().split()))
    print((n - mx) * 2 - (k - 1))