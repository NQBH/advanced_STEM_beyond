def solver():
    n, k = map(int, input().split())
    a, b = n, n - 1
    ans = 0
    while k > 0:
        k -= a
        ans += 1
        a, b = b, (b if a != b else b - 1)
    print(ans)
     
t = int(input())
for _ in range(t):
    solver()