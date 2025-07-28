# Bài 2: Đếm phân hoạch với phần tử lớn nhất là k

# Dictionary cho memoization
memo = {}

def partitions_with_max_part(n, max_part):
    """Tính số phân hoạch của n với các phần không vượt quá max_part"""
    if n == 0:
        return 1
    if n < 0 or max_part <= 0:
        return 0
    
    key = (n, max_part)
    if key in memo:
        return memo[key]
    
    # Không dùng max_part
    result = partitions_with_max_part(n, max_part - 1)
    
    # Dùng ít nhất 1 lần max_part
    if n >= max_part:
        result += partitions_with_max_part(n - max_part, max_part)
    
    memo[key] = result
    return result

def partitions_with_exact_max(n, k):
    """Tính số phân hoạch của n với phần tử lớn nhất CHÍNH XÁC là k"""
    if k > n:
        return 0
    if k == n:
        return 1  # Chỉ có phân hoạch (n)
    
    # Số phân hoạch có max <= k trừ số phân hoạch có max <= k-1
    return partitions_with_max_part(n, k) - partitions_with_max_part(n, k - 1)

def partitions_with_exact_parts(n, k):
    """Tính p_k(n) - số phân hoạch của n với ĐÚNG k phần"""
    if k == 0:
        return 1 if n == 0 else 0
    if k > n:
        return 0
    
    # Khởi tạo bảng DP
    dp = [[0 for _ in range(k + 1)] for _ in range(n + 1)]
    dp[0][0] = 1
    
    for i in range(1, n + 1):
        for j in range(1, min(i, k) + 1):
            for part in range(1, i + 1):
                if i - part >= 0 and j - 1 >= 0:
                    dp[i][j] += dp[i - part][j - 1]
    
    return dp[n][k]

def generate_and_count(n, target_max, current_sum=0, current_max=0, 
                      current_partition=None, count_ref=None):
    """Sinh và đếm trực tiếp các phân hoạch có max = target_max"""
    if current_partition is None:
        current_partition = []
    if count_ref is None:
        count_ref = [0]  # Sử dụng list để pass by reference
    
    if current_sum == n:
        if current_max == target_max:
            count_ref[0] += 1
            # In ra phân hoạch
            print(f"({', '.join(map(str, current_partition))})", end=" ")
        return
    
    if current_sum > n:
        return
    
    start = target_max if not current_partition else min(target_max, current_partition[-1])
    
    for i in range(start, 0, -1):
        if current_sum + i <= n:
            current_partition.append(i)
            generate_and_count(n, target_max, current_sum + i, 
                             max(current_max, i), current_partition, count_ref)
            current_partition.pop()

def main():
    print("Nhập n và k: ", end="")
    try:
        n, k = map(int, input().split())
    except:
        print("Vui lòng nhập hai số nguyên!")
        return
    
    if n <= 0 or k <= 0:
        print("n và k phải là số nguyên dương!")
        return
    
    print(f"Phân tích cho n = {n}, k = {k}:")
    print("=" * 40)
    
    # Clear memo cho tính toán mới
    memo.clear()
    
    # Tính p_max(n, k) - số phân hoạch có phần tử lớn nhất là k
    p_max = partitions_with_exact_max(n, k)
    print(f"p_max({n}, {k}) = {p_max}")
    
    # Tính p_k(n) - số phân hoạch có đúng k phần
    p_k = partitions_with_exact_parts(n, k)
    print(f"p_{k}({n}) = {p_k}")
    
    print("\nSo sánh:")
    if p_max > p_k:
        print(f"p_max({n}, {k}) > p_{k}({n})")
    elif p_max < p_k:
        print(f"p_max({n}, {k}) < p_{k}({n})")
    else:
        print(f"p_max({n}, {k}) = p_{k}({n})")
    
    # Liệt kê các phân hoạch có max = k (nếu số lượng không quá lớn)
    if p_max <= 20:
        print(f"\nCác phân hoạch có phần tử lớn nhất là {k}:")
        count_ref = [0]
        generate_and_count(n, k, count_ref=count_ref)
        print(f"\nTổng: {count_ref[0]} phân hoạch")
    
    # Tính một số giá trị khác để so sánh
    print("\nBảng so sánh p_max và p_k cho các giá trị khác:")
    print("k\tp_max(n,k)\tp_k(n)")
    print("-" * 24)
    
    for i in range(1, min(n, 10) + 1):
        pm = partitions_with_exact_max(n, i)
        pk = partitions_with_exact_parts(n, i)
        print(f"{i}\t{pm}\t\t{pk}")

if __name__ == "__main__":
    main()