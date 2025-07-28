def p_k(n, k):
    # dp[i][j] = số phân hoạch i thành đúng j phần tử
    dp = [[0] * (k+1) for _ in range(n+1)]
    dp[0][0] = 1
    for num in range(1, n+1):
        for i in range(n, num-1, -1):
            for j in range(1, k+1):
                dp[i][j] += dp[i - num][j - 1]
    return dp[n][k]

def p_max(n, k):
    # dp[i][j] = số phân hoạch i với phần tử không vượt quá j
    dp = [[0]*(k+1) for _ in range(n+1)]
    for j in range(k+1):
        dp[0][j] = 1
    for i in range(1, n+1):
        for j in range(1, k+1):
            if i >= j:
                dp[i][j] = dp[i][j-1] + dp[i-j][j]
            else:
                dp[i][j] = dp[i][j-1]
    return dp[n][k] - (dp[n][k-1] if k > 0 else 0)

if __name__ == "__main__":
    n = int(input("Nhập n: "))
    k = int(input("Nhập k: "))
    print(f"p_{k}({n}) =", p_k(n, k))
    print(f"p_max({n}, {k}) =", p_max(n, k))