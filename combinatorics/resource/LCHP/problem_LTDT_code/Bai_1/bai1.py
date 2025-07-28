def print_ferrers(partition):
    """In biểu đồ Ferrers và biểu đồ chuyển vị"""
    print("Phân hoạch:", " + ".join(map(str, partition)))
    
    # In biểu đồ Ferrers gốc
    print("Biểu đồ Ferrers:")
    for part in partition:
        print("*" * part)
    
    # In biểu đồ Ferrers chuyển vị
    print("Biểu đồ Ferrers chuyển vị:")
    if partition:
        max_col = partition[0]  # Phần tử đầu tiên (lớn nhất)
        for col in range(max_col):
            line = ""
            for row in range(len(partition)):
                if col < partition[row]:
                    line += "*"
            print(line)
    print("-" * 30)

def generate_partitions(n, k, current_sum=0, last_value=None, current_partition=None):
    """Sinh tất cả phân hoạch của n với đúng k phần"""
    if current_partition is None:
        current_partition = []
    if last_value is None:
        last_value = n
    
    # Nếu đã có đủ k phần
    if len(current_partition) == k:
        if current_sum == n:
            print_ferrers(current_partition[:])
            return [current_partition[:]]
        return []
    
    # Nếu tổng đã bằng n nhưng chưa đủ phần
    if current_sum == n:
        return []
    
    result = []
    remaining = n - current_sum
    remaining_parts = k - len(current_partition)
    
    # Thử các giá trị từ 1 đến min(last_value, remaining - remaining_parts + 1)
    for i in range(1, min(last_value, remaining - remaining_parts + 2)):
        if remaining >= i:
            current_partition.append(i)
            result.extend(generate_partitions(n, k, current_sum + i, i, current_partition))
            current_partition.pop()
    
    return result

def count_partitions_k_parts(n, k):
    """Đếm số phân hoạch của n với đúng k phần (không in ra)"""
    def dp_count(n, k, max_val):
        if k == 0:
            return 1 if n == 0 else 0
        if n <= 0 or max_val <= 0:
            return 0
        
        count = 0
        for i in range(1, min(max_val, n) + 1):
            count += dp_count(n - i, k - 1, i)
        return count
    
    return dp_count(n, k, n)

def main():
    try:
        n = int(input("Nhập n: "))
        k = int(input("Nhập k: "))
        
        # Kiểm tra điều kiện hợp lệ
        if k > n or k <= 0 or n <= 0:
            print("Không có phân hoạch nào thỏa mãn!")
            return
        
        print(f"Các phân hoạch của {n} với đúng {k} phần:")
        print("=" * 40)
        
        partitions = generate_partitions(n, k)
        
        print(f"Tổng cộng có {len(partitions)} phân hoạch.")
        
        # So sánh với công thức tính nhanh
        quick_count = count_partitions_k_parts(n, k)
        print(f"Kiểm tra bằng công thức: p_{k}({n}) = {quick_count}")
        
    except ValueError:
        print("Vui lòng nhập số nguyên hợp lệ!")

if __name__ == "__main__":
    main()