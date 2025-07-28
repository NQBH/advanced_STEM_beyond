def generate_partitions(n, k, max_val=None):
    """Sinh tất cả phân hoạch của n thành đúng k phần"""
    if max_val is None:
        max_val = n
    
    if k == 1:
        if 1 <= n <= max_val:
            return [[n]]
        else:
            return []
    
    if k > n or n <= 0:
        return []
    
    partitions = []
    min_first = max(1, (n + k - 1) // k)
    max_first = min(n - k + 1, max_val)
    
    for first in range(min_first, max_first + 1):
        remaining_partitions = generate_partitions(n - first, k - 1, first)
        for partition in remaining_partitions:
            partitions.append([first] + partition)
    
    return partitions

def is_self_conjugate(partition):
    """Kiểm tra phân hoạch có tự liên hợp hay không"""
    # Tạo Ferrers transpose
    max_width = partition[0] if partition else 0
    conjugate = []
    for col in range(max_width):
        count = 0
        for row in range(len(partition)):
            if col < partition[row]:
                count += 1
            else:
                break
        if count > 0:
            conjugate.append(count)
        else:
            break
    return partition == conjugate

def count_self_conjugate_partitions(n, k):
    """Đếm số phân hoạch tự liên hợp của n thành k phần"""
    partitions = generate_partitions(n, k)
    self_conjugate_count = 0
    self_conjugate_partitions = []
    
    for partition in partitions:
        if is_self_conjugate(partition):
            self_conjugate_count += 1
            self_conjugate_partitions.append(partition)
    
    return self_conjugate_count, self_conjugate_partitions

def count_partitions_k_parts(n, k):
    """Đếm số phân hoạch của n thành đúng k phần"""
    if k == 1:
        return 1 if 1 <= n <= k else 0
    if k > n or n <= 0:
        return 0
    return sum(count_partitions_k_parts(n - m, k - 1, m) for m in range(1, min(k, n) + 1))

def main():
    try:
        n = int(input("Nhập n: "))
        k = int(input("Nhập k: "))
        
        if n <= 0 or k <= 0:
            print("n và k phải là số nguyên dương!")
            return
        
        # Tính p_selfconj(n, k)
        self_conjugate_count, self_conjugate_partitions = count_self_conjugate_partitions(n, k)
        print(f"\nSố phân hoạch tự liên hợp của {n} thành {k} phần: {self_conjugate_count}")
        print("Các phân hoạch tự liên hợp:")
        for partition in self_conjugate_partitions:
            print(partition)
        
        # Tính p_k(n)
        p_k = count_partitions_k_parts(n, k)
        print(f"\nSố phân hoạch của {n} thành {k} phần: {p_k}")
        
        # So sánh
        print("\nSo sánh:")
        if self_conjugate_count > p_k:
            print(f"p_selfconj({n}, {k}) > p_{k}({n})")
        elif self_conjugate_count < p_k:
            print(f"p_selfconj({n}, {k}) < p_{k}({n})")
        else:
            print(f"p_selfconj({n}, {k}) = p_{k}({n})")
            
    except ValueError:
        print("Vui lòng nhập số nguyên hợp lệ!")

if __name__ == "__main__":
    main()