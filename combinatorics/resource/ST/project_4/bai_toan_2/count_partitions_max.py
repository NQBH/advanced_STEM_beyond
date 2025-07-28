def count_partitions_max(n, k):
    # Tao bang dp voi n+1 hang va k+1 cot, khoi tao bang 0
    dp = [[0] * (k + 1) for _ in range(n + 1)]

    # Co 1 cach phan hoach 0 voi moi k (khong chia gi ca)
    for j in range(k + 1):
        dp[0][j] = 1

    # Duyet qua cac gia tri i tu 1 den n
    for i in range(1, n + 1):
        for j in range(1, k + 1):
            if i - j >= 0:
                # Co 2 truong hop: khong chon j va chon j
                dp[i][j] = dp[i][j - 1] + dp[i - j][j]
            else:
                # Chi co the khong chon j
                dp[i][j] = dp[i][j - 1]

    return dp[n][k]

# Nhap n va k tu ban phim
n = int(input("Nhap n: "))
k = int(input("Nhap k: "))

# In ket qua ra man hinh
print(f"So phan hoach cua {n} voi so lon nhat la {k} la: {count_partitions_max(n, k)}")