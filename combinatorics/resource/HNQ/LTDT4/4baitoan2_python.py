#!/usr/bin/env python3
"""
Bài toán 2: Đếm số phân hoạch
Tính p_k(n) và p_max(n,k), so sánh kết quả
"""

class PartitionCountingSolver:
    def __init__(self):
        # Biến chính: dp - bảng Dynamic Programming
        self.dp = []
    
    def generate_partitions_recursive(self, n, k, min_val, current, result):
        """Hàm đệ quy sinh phân hoạch (tương tự bài toán 1)"""
        if k == 1:
            if n >= min_val:
                current.append(n)
                result.append(current[:])
                current.pop()
            return
        
        for i in range(min_val, n // k + 1):
            current.append(i)
            self.generate_partitions_recursive(n - i, k - 1, i, current, result)
            current.pop()
    
    def compute_partition_count_dp(self, n, k):
        """
        Tính p(n,k) bằng Dynamic Programming
        
        Công thức đệ quy: p(n,k) = p(n-1,k-1) + p(n-k,k)
        
        Ý nghĩa:
        - p(n-1,k-1): Số cách khi thêm phần mới có giá trị 1
        - p(n-k,k): Số cách khi tăng mỗi phần hiện có lên 1
        
        Args:
            n: Số cần phân hoạch
            k: Số phần
            
        Returns:
            Số phân hoạch của n thành đúng k phần
        """
        # Khởi tạo bảng DP
        self.dp = [[0] * (k + 1) for _ in range(n + 1)]
        
        # Base cases
        # p(i,1) = 1: chỉ có 1 cách phân hoạch i thành 1 phần (chính là i)
        for i in range(1, n + 1):
            self.dp[i][1] = 1
        
        # p(j,j) = 1: chỉ có 1 cách phân hoạch j thành j phần (1+1+...+1)
        for j in range(1, min(n, k) + 1):
            self.dp[j][j] = 1
        
        # Fill bảng DP theo công thức đệ quy
        for i in range(2, n + 1):
            for j in range(2, min(i, k) + 1):
                # Áp dụng công thức: p(i,j) = p(i-1,j-1) + p(i-j,j)
                self.dp[i][j] = self.dp[i-1][j-1] + self.dp[i-j][j]
        
        return self.dp[n][k]
    
    def compute_partition_with_max(self, n, max_val):
        """
        Tính p_max(n,k) - số phân hoạch có phần tử lớn nhất là k
        
        Args:
            n: Số cần phân hoạch
            max_val: Giá trị lớn nhất trong phân hoạch
            
        Returns:
            Số phân hoạch của n có phần tử lớn nhất là max_val
        """
        if max_val > n:
            return 0
        if max_val == n:
            return 1
        
        # Sinh tất cả phân hoạch và đếm những phân hoạch có max = max_val
        all_partitions = []
        
        # Sinh phân hoạch với tất cả số phần có thể
        for parts in range(1, n + 1):
            current = []
            partitions_with_parts = []
            self.generate_partitions_recursive(n, parts, 1, current, partitions_with_parts)
            
            # Sắp xếp và thêm vào danh sách tổng
            for partition in partitions_with_parts:
                partition.sort(reverse=True)
                all_partitions.append(partition)
        
        # Đếm số phân hoạch có max = max_val
        count = 0
        for partition in all_partitions:
            if partition and partition[0] == max_val:
                count += 1
        
        return count
    
    def print_dp_table(self, n, k):
        """In bảng Dynamic Programming một cách trực quan"""
        print("Bảng Dynamic Programming p(i,j):")
        
        # Header
        print(f"{'i\\j':<4}", end="")
        for j in range(1, k + 1):
            print(f"{j:>4}", end="")
        print()
        
        # Nội dung bảng
        for i in range(1, n + 1):
            print(f"{i:<4}", end="")
            for j in range(1, k + 1):
                print(f"{self.dp[i][j]:>4}", end="")
            print()
        print()
    
    def solve_problem2(self, n, k):
        """
        Giải bài toán 2: Đếm số phân hoạch
        
        Args:
            n: Số cần phân hoạch
            k: Số phần hoặc giá trị max
        """
        print("=== BÀI TOÁN 2: ĐẾM SỐ PHÂN HOẠCH ===")
        print(f"Tham số: n = {n}, k = {k}\n")
        
        # Tính p_k(n) bằng Dynamic Programming
        pk_n = self.compute_partition_count_dp(n, k)
        print(f"p_{k}({n}) = {pk_n}")
        print(f"Giải thích: Số cách phân hoạch {n} thành đúng {k} phần\n")
        
        # Tính p_max(n,k)
        pmax_n_k = self.compute_partition_with_max(n, k)
        print(f"p_max({n},{k}) = {pmax_n_k}")
        print(f"Giải thích: Số cách phân hoạch {n} có phần tử lớn nhất là {k}\n")
        
        # So sánh kết quả
        print("So sánh kết quả:")
        print(f"p_{k}({n}) ", end="")
        if pk_n == pmax_n_k:
            comparison = "="
        elif pk_n > pmax_n_k:
            comparison = ">"
        else:
            comparison = "<"
        print(f"{comparison} p_max({n},{k})\n")
        
        # In bảng DP
        self.print_dp_table(n, k)
        
        # Giải thích công thức đệ quy
        print("Công thức đệ quy: p(n,k) = p(n-1,k-1) + p(n-k,k)")
        print("- p(n-1,k-1): Số cách khi phần nhỏ nhất = 1")
        print("- p(n-k,k): Số cách khi tất cả các phần ≥ 2\n")
        
        # Verification bằng enumeration cho n,k nhỏ
        if n <= 10 and k <= 6:
            print("Verification bằng enumeration:")
            current = []
            partitions = []
            self.generate_partitions_recursive(n, k, 1, current, partitions)
            
            print("Tất cả các phân hoạch:")
            for i, partition in enumerate(partitions):
                partition.sort(reverse=True)
                print(f"{i + 1}. ({','.join(map(str, partition))})")
            print(f"Tổng cộng: {len(partitions)} phân hoạch ✓\n")

def main():
    print("CHƯƠNG TRÌNH GIẢI BÀI TOÁN 2: ĐẾM SỐ PHÂN HOẠCH")
    print("=" * 60 + "\n")
    
    try:
        n = int(input("Nhập n (số cần phân hoạch): "))
        k = int(input("Nhập k (số phần hoặc giá trị max): "))
        print()
        
        # Kiểm tra tính hợp lệ
        if n <= 0 or k <= 0:
            print("Lỗi: n và k phải là số nguyên dương!")
            return
        
        solver = PartitionCountingSolver()
        solver.solve_problem2(n, k)
        
        # Demo với các test cases
        print("=" * 60)
        print("DEMO VỚI CÁC TEST CASES KHÁC:")
        print("=" * 60)
        
        test_cases = [(6, 3), (7, 4), (8, 4)]
        
        for n_test, k_test in test_cases:
            print()
            solver.solve_problem2(n_test, k_test)
            
    except ValueError:
        print("Lỗi: Vui lòng nhập số nguyên hợp lệ!")
    except Exception as e:
        print(f"Lỗi không mong muốn: {e}")

if __name__ == "__main__":
    main()
        