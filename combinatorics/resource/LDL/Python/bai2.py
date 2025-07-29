def count_partitions_exact_parts(n, k):
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 1  # Co 1 cach phan hoach 0 thanh 0 phan

    for i in range(1, n + 1):        # Tong can dat
        for j in range(1, k + 1):    # So phan
            if i >= j:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j]
            else:
                dp[i][j] = dp[i - 1][j - 1]
    return dp[n][k]


def count_partitions_max(n, k):
    def count_p_le_k(n, k):
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        for j in range(k + 1):
            dp[0][j] = 1  # Co 1 cach phan hoach 0

        for i in range(1, n + 1):
            for j in range(1, k + 1):
                if i >= j:
                    dp[i][j] = dp[i][j - 1] + dp[i - j][j]
                else:
                    dp[i][j] = dp[i][j - 1]
        return dp[n][k]

    if k > n:
        return 0
    return count_p_le_k(n, k) - count_p_le_k(n, k - 1)

if __name__ == "__main__":
    n = int(input("Nhap n: "))
    k = int(input("Nhap k: "))

    p_k = count_partitions_exact_parts(n, k)
    p_max = count_partitions_max(n, k)

    print(f"\np_k({n}) = {p_k} ")
    print(f"p_max({n},{k}) = {p_max}")