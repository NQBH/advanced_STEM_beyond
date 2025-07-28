# graded
def stirling_ii(n):
    dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    dp[0][0] = 1  

    for i in range(1, n + 1):
        for k in range(1, i + 1):
            dp[i][k] = (i - 1) * dp[i - 1][k] + dp[i - 1][k - 1]

    return dp[n] 

n = int(input("Nhap n: "))
values = stirling_ii(n)
for k in range(n + 1):
    print(f"[{n}|{k}] = {values[k]}")