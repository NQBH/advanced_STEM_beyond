t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    ans = 0
    if n % 2 == 1:
        n -= k
        ans = 1
    k -= 1
    ans += (n + k - 1) // k
    print(ans)