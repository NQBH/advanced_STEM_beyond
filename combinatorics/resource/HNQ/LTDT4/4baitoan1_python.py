#!/usr/bin/env python3
"""
Bài toán 1: Ferrers & Ferrers Transpose Diagrams
Sinh tất cả phân hoạch và vẽ biểu đồ Ferrers và transpose
"""

class FerrersDiagramSolver:
    def __init__(self):
        pass
    
    def generate_partitions_recursive(self, n, k, min_val, current, result):
        """
        Hàm đệ quy sinh phân hoạch
        
        Args:
            n: Tổng còn lại cần phân hoạch
            k: Số phần còn lại
            min_val: Giá trị tối thiểu của phần tiếp theo (đảm bảo thứ tự)
            current: Phân hoạch hiện tại đang xây dựng
            result: Danh sách kết quả chứa tất cả phân hoạch
        """
        # Base case: chỉ còn 1 phần
        if k == 1:
            if n >= min_val:
                current.append(n)
                result.append(current[:])  # Deep copy
                current.pop()
            return
        
        # Recursive case: thử các giá trị từ min_val đến n//k
        # Điều kiện i <= n//k đảm bảo có thể phân phối đều cho k phần
        for i in range(min_val, n // k + 1):
            current.append(i)
            self.generate_partitions_recursive(n - i, k - 1, i, current, result)
            current.pop()
    
    def generate_partitions(self, n, k):
        """
        Sinh tất cả phân hoạch của n thành k phần
        
        Args:
            n: Số cần phân hoạch
            k: Số phần
            
        Returns:
            List các phân hoạch, mỗi phân hoạch được sắp xếp giảm dần
        """
        result = []
        current = []
        
        self.generate_partitions_recursive(n, k, 1, current, result)
        
        # Sắp xếp các phần theo thứ tự giảm dần (chuẩn partition)
        for partition in result:
            partition.sort(reverse=True)
        
        return result
    
    def compute_conjugate(self, partition):
        """
        Tính conjugate partition bằng cách đếm số phần >= i với mỗi i
        
        Định lý: Nếu λ = (λ₁, λ₂, ..., λₖ), thì λᵀ = (λ₁ᵀ, λ₂ᵀ, ...)
        với λᵢᵀ = |{j : λⱼ ≥ i}| (số phần trong λ có giá trị ≥ i)
        
        Args:
            partition: Phân hoạch gốc (đã sắp xếp giảm dần)
            
        Returns:
            Conjugate partition
        """
        if not partition:
            return []
        
        conjugate = []
        max_part = partition[0]  # Phần lớn nhất
        
        # Với mỗi cột i (từ 1 đến max_part)
        for i in range(1, max_part + 1):
            count = 0
            # Đếm số phần >= i
            for part in partition:
                if part >= i:
                    count += 1
                else:
                    break  # Tối ưu: dừng sớm vì đã sort giảm dần
            
            if count > 0:
                conjugate.append(count)
        
        return conjugate
    
    def draw_ferrers_diagram(self, partition, title):
        """
        Vẽ Ferrers diagram bằng ký tự '*'
        
        Args:
            partition: Phân hoạch cần vẽ
            title: Tiêu đề của diagram
        """
        print(f"{title}:")
        for part in partition:
            print("* " * part)
        print()
    
    def format_partition(self, partition):
        """Format partition để hiển thị đẹp"""
        if not partition:
            return "{}"
        return "(" + ",".join(map(str, partition)) + ")"
    
    def solve_problem1(self, n, k):
        """
        Giải bài toán 1: Ferrers & Ferrers Transpose Diagrams
        
        Args:
            n: Số cần phân hoạch  
            k: Số phần
        """
        print("=== BÀI TOÁN 1: FERRERS & FERRERS TRANSPOSE DIAGRAMS ===")
        print(f"Tham số: n = {n}, k = {k}\n")
        
        # Sinh tất cả phân hoạch
        partitions = self.generate_partitions(n, k)
        print(f"Số phân hoạch p_k(n) = p_{k}({n}) = {len(partitions)}\n")
        
        # Xử lý từng phân hoạch
        for i, partition in enumerate(partitions):
            print(f"--- PHÂN HOẠCH {i + 1} ---")
            print(f"λ = {self.format_partition(partition)}\n")
            
            # Vẽ Ferrers diagram gốc
            self.draw_ferrers_diagram(partition, "Ferrers Diagram F")
            
            # Tính và vẽ conjugate
            conjugate = self.compute_conjugate(partition)
            print(f"Conjugate λ^T = {self.format_partition(conjugate)}\n")
            self.draw_ferrers_diagram(conjugate, "Ferrers Transpose Diagram F^T")
            
            # Kiểm tra tính chất (λ^T)^T = λ
            double_conjugate = self.compute_conjugate(conjugate)
            is_correct = (partition == double_conjugate)
            print(f"Kiểm tra (λ^T)^T = λ: {'✓' if is_correct else '✗'}")
            
            print("=" * 50 + "\n")

def main():
    print("CHƯƠNG TRÌNH GIẢI BÀI TOÁN 1: FERRERS & FERRERS TRANSPOSE DIAGRAMS")
    print("=" * 70 + "\n")
    
    try:
        n = int(input("Nhập n (số cần phân hoạch): "))
        k = int(input("Nhập k (số phần): "))
        print()
        
        # Kiểm tra tính hợp lệ
        if n <= 0 or k <= 0:
            print("Lỗi: n và k phải là số nguyên dương!")
            return
        
        if k > n:
            print("Không có phân hoạch nào vì k > n!")
            return
        
        solver = FerrersDiagramSolver()
        solver.solve_problem1(n, k)
        
        # Demo với các test cases
        print("\n" + "=" * 70)
        print("DEMO VỚI CÁC TEST CASES KHÁC:")
        print("=" * 70)
        
        test_cases = [(4, 2), (5, 3), (6, 2)]
        
        for n_test, k_test in test_cases:
            print()
            solver.solve_problem1(n_test, k_test)
            
    except ValueError:
        print("Lỗi: Vui lòng nhập số nguyên hợp lệ!")
    except Exception as e:
        print(f"Lỗi không mong muốn: {e}")

if __name__ == "__main__":
    main()