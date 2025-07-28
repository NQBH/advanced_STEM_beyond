def print_diagram(partition):
    """In biểu đồ Ferrers từ một phân hoạch."""
    for part in partition:
        print('* ' * part)

def get_transpose(partition):
    """Tính phân hoạch chuyển vị (liên hợp)."""
    if not partition:
        return []
    
    # Số phần tử của phân hoạch chuyển vị bằng giá trị phần tử lớn nhất
    num_rows_transpose = partition[0]
    transpose = [0] * num_rows_transpose
    
    for part in partition:
        for i in range(part):
            transpose[i] += 1
    return transpose

def find_partitions(n, k):
    """Hàm bao ngoài để bắt đầu quá trình đệ quy."""

    # Hàm đệ quy quay lui để tìm các phân hoạch
    def backtrack(target, num_parts_left, current_partition, max_val):
        # Trường hợp cơ sở: đã đủ k phần tử
        if num_parts_left == 0:
            if target == 0:
                print(f"Phan hoach: {current_partition}")
                print("Bieu do Ferrers:")
                print_diagram(current_partition)
                
                transpose = get_transpose(current_partition)
                print(f"\nBieu do chuyen vi (Phan hoach lien hop: {transpose}):")
                print_diagram(transpose)
                print("-" * 25)
            return

        # Thử các giá trị có thể cho phần tử tiếp theo
        # Giá trị phải nhỏ hơn hoặc bằng max_val để đảm bảo thứ tự không tăng
        for i in range(min(target, max_val), 0, -1):
            # Điều kiện để đảm bảo các phần tử còn lại có thể tạo thành tổng
            if target - i >= num_parts_left - 1:
                backtrack(target - i, num_parts_left - 1, current_partition + [i], i)

    if n < k or k <= 0:
        print("Khong co phan hoach nao.")
        return
        
    backtrack(n, k, [], n - k + 1)

# Chạy chương trình chính
if __name__ == "__main__":
    n = int(input("Nhap so nguyen n: "))
    k = int(input("Nhap so phan tu k: "))
    find_partitions(n, k)