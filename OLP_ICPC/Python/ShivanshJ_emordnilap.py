t = int(input())
for _ in range(t):
    n = int(input())
    nf = 1
    mod = int(1e9 + 7)
    for i in range(n):
        nf = nf * (i + 1)
        nf %= mod
    ans = n * (n - 1) * nf
    ans %= mod
    print(ans)