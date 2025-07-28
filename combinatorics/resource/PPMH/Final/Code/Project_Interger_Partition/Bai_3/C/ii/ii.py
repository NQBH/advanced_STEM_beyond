def count_self_conjugate_dp(n, k):
    # dp[total][parts][max_val]
    dp = [[[0] * (n + 1) for _ in range(k + 1)] for _ in range(n + 1)]
    dp[0][0][n] = 1 

    for total in range(n + 1):
        for parts in range(k + 1):
            for max_val in range(n + 1):
                val = dp[total][parts][max_val]
                if val == 0:
                    continue
                for i in range(min(max_val, n - total), 0, -2): 
                    if total + i <= n and parts + 1 <= k:
                        dp[total + i][parts + 1][i] += val
    return sum(dp[n][k])

n = int(input("Nhập n: "))
k = int(input("Nhập k: "))
print("Quy hoạch động:", count_self_conjugate_dp(n, k))