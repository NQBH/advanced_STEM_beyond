def generate_partitions(n, k, max_val=None):
    """
    Sinh tất cả các phân hoạch của n thành đúng k phần
    max_val: giá trị tối đa cho phần tử đầu tiên (để đảm bảo không tăng)
    """
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
    
    # Phần tử đầu tiên có thể từ max(1, ceil(n/k)) đến min(n-k+1, max_val)
    min_first = max(1, (n + k - 1) // k)  # ceil(n/k)
    max_first = min(n - k + 1, max_val)
    
    for first in range(min_first, max_first + 1):
        # Sinh các phân hoạch cho (n-first) thành (k-1) phần
        remaining_partitions = generate_partitions(n - first, k - 1, first)
        for partition in remaining_partitions:
            partitions.append([first] + partition)
    
    return partitions

def print_ferrers_diagram(partition, title):
    """In biểu đồ Ferrers với tiêu đề"""
    print(f"{title}:")
    for part in partition:
        print("*" * part)
    print()

def get_conjugate_partition(partition):
    """
    Tìm phân hoạch liên hợp (chuyển vị) từ biểu đồ Ferrers
    """
    if not partition:
        return []
    
    # Tạo ma trận từ biểu đồ Ferrers
    max_width = partition[0] if partition else 0
    rows = len(partition)
    
    # Đếm số dấu * ở mỗi cột
    conjugate = []
    for col in range(max_width):
        count = 0
        for row in range(rows):
            if col < partition[row]:
                count += 1
            else:
                break
        if count > 0:
            conjugate.append(count)
        else:
            break
    
    return conjugate

def main():
    try:
        n = int(input("Nhập n: "))
        k = int(input("Nhập k: "))
        
        if n <= 0 or k <= 0:
            print("n và k phải là số nguyên dương!")
            return
        
        print(f"\n=== TẤT CẢ PHÂN HOẠCH pk({n}) VỚI k={k} ===\n")
        
        partitions = generate_partitions(n, k)
        
        if not partitions:
            print(f"Không tồn tại phân hoạch của {n} thành đúng {k} phần!")
            return
        
        print(f"Tổng số phân hoạch: {len(partitions)}\n")
        
        for i, partition in enumerate(partitions, 1):
            print(f"--- Phân hoạch {i}: {partition} ---")
            
            # In biểu đồ Ferrers gốc
            print_ferrers_diagram(partition, "Biểu đồ Ferrers F")
            
            # Tìm và in biểu đồ Ferrers chuyển vị
            conjugate = get_conjugate_partition(partition)
            print_ferrers_diagram(conjugate, "Biểu đồ Ferrers chuyển vị F^T")
            
    except ValueError:
        print("Vui lòng nhập số nguyên hợp lệ!")
    except KeyboardInterrupt:
        print("\nChương trình đã dừng!")

if __name__ == "__main__":
    main()