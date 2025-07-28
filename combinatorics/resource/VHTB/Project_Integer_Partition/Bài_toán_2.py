def count_partitions(n, k):
    dp = [[0] * (k+1) for _ in range(n+1)]
    dp[0][0] = 1
    for i in range(1, n+1):
        for j in range(1, k+1):
            if i - j >= 0:
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j]
    return dp[n][k]
print("p(8,4) =", count_partitions(8, 4))
