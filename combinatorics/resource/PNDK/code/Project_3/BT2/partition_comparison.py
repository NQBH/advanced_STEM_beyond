def generate_all_partitions(n, max_val=None):
    """Sinh tất cả phân hoạch của n"""
    if max_val is None:
        max_val = n
    
    if n == 0:
        return [[]]
    
    partitions = []
    for first in range(min(n, max_val), 0, -1):
        for partition in generate_all_partitions(n - first, first):
            partitions.append([first] + partition)
    
    return partitions

def count_partitions_with_max(n, k):
    """Đếm số phân hoạch của n có phần tử lớn nhất là k"""
    if k > n or k <= 0:
        return 0
    
    partitions = generate_all_partitions(n)
    count = 0
    
    for partition in partitions:
        if partition and partition[0] == k:
            count += 1
    
    return count

def generate_partitions_k_parts(n, k, max_val=None):
    """Sinh phân hoạch của n thành đúng k phần"""
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
        remaining_partitions = generate_partitions_k_parts(n - first, k - 1, first)
        for partition in remaining_partitions:
            partitions.append([first] + partition)
    
    return partitions

def count_partitions_k_parts(n, k):
    """Đếm số phân hoạch của n thành đúng k phần"""
    partitions = generate_partitions_k_parts(n, k)
    return len(partitions)

def main():
    try:
        n = int(input("Nhập n: "))
        k = int(input("Nhập k: "))
        
        if n <= 0 or k <= 0:
            print("n và k phải là số nguyên dương!")
            return
        
        # Tính p_max(n, k)
        p_max = count_partitions_with_max(n, k)
        
        # Tính p_k(n)
        p_k = count_partitions_k_parts(n, k)
        
        print(f"\nKết quả:")
        print(f"p_max({n}, {k}) = {p_max}")
        print(f"p_{k}({n}) = {p_k}")
        
        print(f"\nSo sánh:")
        if p_max > p_k:
            print(f"p_max({n}, {k}) > p_{k}({n})")
        elif p_max < p_k:
            print(f"p_max({n}, {k}) < p_{k}({n})")
        else:
            print(f"p_max({n}, {k}) = p_{k}({n})")
            
        # Hiển thị chi tiết các phân hoạch
        print(f"\nChi tiết phân hoạch p_max({n}, {k}):")
        partitions_all = generate_all_partitions(n)
        count = 0
        for partition in partitions_all:
            if partition and partition[0] == k:
                print(f"  {partition}")
                count += 1
        if count == 0:
            print("  Không có phân hoạch nào")
            
        print(f"\nChi tiết phân hoạch p_{k}({n}):")
        partitions_k = generate_partitions_k_parts(n, k)
        if partitions_k:
            for partition in partitions_k:
                print(f"  {partition}")
        else:
            print("  Không có phân hoạch nào")
        
    except ValueError:
        print("Vui lòng nhập số nguyên hợp lệ!")

if __name__ == "__main__":
    main()