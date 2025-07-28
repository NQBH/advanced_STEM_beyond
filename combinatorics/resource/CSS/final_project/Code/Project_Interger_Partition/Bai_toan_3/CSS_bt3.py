def is_self_conjugate(partition):
    max_val = max(partition)
    transpose = [sum(1 for x in partition if x >= i) for i in range(1, max_val + 1)]
    return partition == tuple(transpose)

def generate_self_conjugate(n, k, max_val, current, results):
    if k == 0:
        if n == 0 and is_self_conjugate(current):
            results.append(current[:])
        return
    if n < k:
        return
    for i in range(1, min(n - k + 1, max_val) + 1):
        current.append(i)
        generate_self_conjugate(n - i, k - 1, i, current, results)
        current.pop()

def count_self_conjugate_recursive(n, k):
    if k == 1:
        return 1 if n == 1 else 0
    if n < k or k <= 0:
        return 0
    result = 0
    for m in range(1, k // 2 + 1):
        result += count_self_conjugate_recursive(n - k*k + (k - 2*m)*(k - 2*m), k - 2*m)
    return result

def count_self_conjugate_dp(n, k):
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    dp[1][1] = 1
    for i in range(1, n + 1):
        for j in range(1, k + 1):
            for m in range(1, j // 2 + 1):
                if i - j*j + (j - 2*m)*(j - 2*m) >= 0:
                    dp[i][j] += dp[i - j*j + (j - 2*m)*(j - 2*m)][j - 2*m]
    return dp[n][k]

def count_odd_partitions(n):
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    dp[0][0] = 1
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            dp[i][j] = dp[i - j][j] + (dp[i - 1][j - 1] if j > 1 else 0)
    return sum(dp[n][k] for k in range(1, n + 1, 2))

def main():
    n = int(input("Nhap n: "))
    k = int(input("Nhap k: "))
    results = []
    generate_self_conjugate(n, k, n, [], results)
    print(f"p_{k}^{{selfcjg}}({n}) = {len(results)}")
    print("Cac phan hoach tu lien hop:")
    for p in results:
        print(p)
    print(f"p_{k}^{{selfcjg}}({n}) (de quy) = {count_self_conjugate_recursive(n, k)}")
    print(f"p_{k}^{{selfcjg}}({n}) (quy hoach dong) = {count_self_conjugate_dp(n, k)}")
    p_odd = count_odd_partitions(n)
    print(f"So phan hoach co le phan = {p_odd}")
    print(f"So sanh: p_{k}^{{selfcjg}}({n}) <= so phan hoach co le phan is {len(results) <= p_odd}")

if __name__ == "__main__":
    main()