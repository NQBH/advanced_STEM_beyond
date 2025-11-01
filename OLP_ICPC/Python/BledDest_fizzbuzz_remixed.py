t = int(input())
for i in range(t):
    n = int(input())
    ans = 3 * (n // 15)
    n %= 15
    for j in range(n + 1):
        if j % 3 == j % 5:
            ans += 1
    print(ans)