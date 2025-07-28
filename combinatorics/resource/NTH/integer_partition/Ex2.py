def count_p_max(n, k):
    """
    Hàm tính số phân hoạch p_max(n, k)
    Đếm số cách phân hoạch n có phần tử lớn nhất là k
    """
    if n < k or k <= 0:
        return 0  # Không thể có phân hoạch
    if n == k:
        return 1  # Chỉ có một phân hoạch là {k}

    target = n - k  # Bài toán quy về: phân hoạch số `target` với các phần tử <= k

    # Bảng quy hoạch động: dp[i][j] là số cách phân hoạch số i với các phần tử <= j
    dp = [[0] * (k + 1) for _ in range(target + 1)]

    # Trường hợp cơ sở: có 1 cách để phân hoạch số 0 (là phân hoạch rỗng)
    for j in range(k + 1):
        dp[0][j] = 1

    # Điền bảng quy hoạch động
    for i in range(1, target + 1):
        for j in range(1, k + 1):
            # Cách 1: Không dùng phần tử j. Số cách bằng phân hoạch i với các phần tử <= j-1
            dp[i][j] = dp[i][j - 1]
            
            # Cách 2: Dùng ít nhất một phần tử j
            if i >= j:
                dp[i][j] += dp[i - j][j]

    return dp[target][k]


if __name__ == "__main__":
    n = int(input("Nhap so nguyen n: "))
    k = int(input("Nhap phan tu lon nhat k: "))
    
    result = count_p_max(n, k)
    print(f"So phan hoach cua {n} co phan tu lon nhat {k} la: {result}")