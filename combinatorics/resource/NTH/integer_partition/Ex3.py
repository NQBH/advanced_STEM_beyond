def get_transpose(partition):
    """Tính phân hoạch chuyển vị (liên hợp)."""
    if not partition:
        return []
    num_rows_transpose = partition[0]
    transpose = [0] * num_rows_transpose
    for part in partition:
        for i in range(part):
            transpose[i] += 1
    return transpose

def is_self_conjugate(partition):
    """Kiểm tra một phân hoạch có tự liên hợp không."""
    # Chuyển đổi sang tuple để so sánh
    return tuple(partition) == tuple(get_transpose(partition))

def generate_and_print_sc(n, k):
    """Tìm và in các phân hoạch tự liên hợp bằng đệ quy quay lui."""
    
    def backtrack(target, num_parts_left, current_partition, max_val):
        if num_parts_left == 0:
            if target == 0:
                if is_self_conjugate(current_partition):
                    print(tuple(current_partition))
            return

        for i in range(min(target, max_val), 0, -1):
            if target - i >= num_parts_left - 1:
                backtrack(target - i, num_parts_left - 1, current_partition + [i], i)

    if n < k or k <= 0:
        print("Khong co phan hoach nao.")
        return
    backtrack(n, k, [], n - k + 1)

def count_self_conjugate_dp(n_max, k_max):
    """Đếm số phân hoạch tự liên hợp bằng quy hoạch động."""
    if n_max < 0 or k_max < 0:
        return 0
        
    # dp[i][j] là số phân hoạch tự liên hợp của i có j phần
    dp = [[0] * (k_max + 1) for _ in range(n_max + 1)]
    dp[0][0] = 1 # Phân hoạch rỗng

    for k in range(1, k_max + 1):
        for i in range(1, n_max + 1):
            prev_n = i - (2 * k - 1)
            if prev_n >= 0:
                sum_prev = sum(dp[prev_n][j] for j in range(k))
                dp[i][k] = sum_prev
    
    return dp[n_max][k_max]

# Hàm chính để chạy chương trình
if __name__ == "__main__":
    n = int(input("Nhap so nguyen n: "))
    k = int(input("Nhap so phan tu k: "))

    print(f"\n--- Cau (a): Cac phan hoach tu lien hop cua {n} co {k} phan ---")
    generate_and_print_sc(n, k)
    
    print(f"\n--- Cau (c): Dem so phan hoach bang Quy hoach dong ---")
    count = count_self_conjugate_dp(n, k)
    print(f"So luong: {count}")