def count_partitions(n, k):
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[0][0] = 1
    for i in range(1, n + 1):
        for j in range(1, min(i + 1, k + 1)):
            dp[i][j] = dp[i - j][j] + (dp[i - 1][j - 1] if j > 1 else 0)
    return dp[n][k]

def count_max_partitions(n, k):
    return count_partitions(n - k, k - 1) if n >= k else 0

def main():
    n = int(input("Nhap n: "))
    k = int(input("Nhap k: "))
    pk_n = count_partitions(n, k)
    pmax_n_k = count_max_partitions(n, k)
    print(f"p_{k}({n}) = {pk_n}")
    print(f"p_max({n},{k}) = {pmax_n_k}")
    print(f"So sanh: p_max({n},{k}) <= p_{k}({n}) is {pmax_n_k <= pk_n}")

if __name__ == "__main__":
    main()