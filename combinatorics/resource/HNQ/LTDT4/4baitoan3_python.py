#!/usr/bin/env python3
"""
Bài toán 3: Số phân hoạch tự liên hợp
Tìm self-conjugate partitions và so sánh với distinct odd parts
"""

from functools import lru_cache

class SelfConjugatePartitionSolver:
    def __init__(self):
        pass
    
    def generate_partitions_recursive(self, n, k, min_val, current, result):
        """Hàm đệ quy sinh phân hoạch (tương tự các bài trước)"""
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
    
    def generate_partitions(self, n, k):
        """Sinh tất cả phân hoạch của n thành k phần"""
        result = []
        current = []
        
        self.generate_partitions_recursive(n, k, 1, current, result)
        
        # Sắp xếp theo thứ tự giảm dần
        for partition in result:
            partition.sort(reverse=True)
        
        return result
    
    def compute_conjugate(self, partition):
        """
        Tính conjugate partition
        
        Định lý: conjugate[i] = số phần trong partition có giá trị >= (i+1)
        """
        if not partition:
            return []
        
        conjugate = []
        max_part = partition[0]
        
        for i in range(1, max_part + 1):
            count = sum(1 for part in partition if part >= i)
            if count > 0:
                conjugate.append(count)
        
        return conjugate
    
    def is_self_conjugate(self, partition):
        """
        Kiểm tra partition có phải self-conjugate không
        
        Định nghĩa: Partition λ là self-conjugate nếu λ = λ^T
        """
        conjugate = self.compute_conjugate(partition)
        return partition == conjugate
    
    def find_self_conjugate_partitions(self, n, k):
        """
        Tìm tất cả phân hoạch tự liên hợp có k phần
        
        Args:
            n: Số cần phân hoạch
            k: Số phần
            
        Returns:
            List các phân hoạch tự liên hợp
        """
        all_partitions = self.generate_partitions(n, k)
        self_conjugate_partitions = []
        
        for partition in all_partitions:
            if self.is_self_conjugate(partition):
                self_conjugate_partitions.append(partition)
        
        return self_conjugate_partitions
    
    def count_partitions_with_odd_parts(self, n):
        """
        Đếm số phân hoạch có số phần lẻ
        
        Args:
            n: Số cần phân hoạch
            
        Returns:
            Số phân hoạch có số phần lẻ
        """
        count = 0
        
        # Duyệt qua tất cả số phần lẻ từ 1 đến n
        for parts in range(1, n + 1, 2):  # 1, 3, 5, 7, ...
            partitions = self.generate_partitions(n, parts)
            count += len(partitions)
        
        return count
    
    def count_partitions_into_distinct_odd_parts(self, n):
        """
        Đếm số phân hoạch thành các phần lẻ khác nhau
        
        Sử dụng backtracking để đếm
        """
        return self._count_distinct_odd_partitions_recursive(n, 1)
    
    def _count_distinct_odd_partitions_recursive(self, n, min_odd):
        """
        Hàm đệ quy đếm phân hoạch thành các phần lẻ khác nhau
        
        Args:
            n: Tổng còn lại
            min_odd: Số lẻ nhỏ nhất có thể sử dụng
            
        Returns:
            Số cách phân hoạch n thành các phần lẻ khác nhau >= min_odd
        """
        if n == 0:
            return 1
        if n < 0 or min_odd > n:
            return 0
        
        count = 0
        
        # Thử tất cả số lẻ từ min_odd
        odd = min_odd
        while odd <= n:
            count += self._count_distinct_odd_partitions_recursive(n - odd, odd + 2)
            odd += 2
        
        return count
    
    @lru_cache(maxsize=None)
    def self_conjugate_recursive(self, n, k):
        """
        Tính số phân hoạch tự liên hợp bằng đệ quy có memoization
        
        Công thức: p_selfcjg_k(n) = p_selfcjg_k(n-1, k-1) + p_selfcjg_k(n-k, k)
        
        Args:
            n: Số cần phân hoạch
            k: Số phần
            
        Returns:
            Số phân hoạch tự liên hợp
        """
        # Base cases
        if k == 1:
            # Self-conjugate với 1 phần: chỉ khi n lẻ (đơn giản hóa)
            return 1 if n % 2 == 1 else 0
        
        if k > n:
            return 0
        if k == n:
            return 1
        if n <= 0:
            return 0
        
        # Áp dụng công thức đệ quy
        return (self.self_conjugate_recursive(n-1, k-1) + 
                self.self_conjugate_recursive(n-k, k))
    
    def self_conjugate_dp(self, n, k):
        """
        Tính số phân hoạch tự liên hợp bằng Dynamic Programming
        
        Args:
            n: Số cần phân hoạch
            k: Số phần
            
        Returns:
            Số phân hoạch tự liên hợp
        """
        # Khởi tạo bảng DP
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        
        # Base cases
        for i in range(1, n + 1):
            dp[i][1] = 1 if i % 2 == 1 else 0
        
        for j in range(1, min(n, k) + 1):
            dp[j][j] = 1
        
        # Fill DP table
        for i in range(2, n + 1):
            for j in range(2, min(i, k) + 1):
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j]
        
        return dp[n][k]
    
    def draw_ferrers_diagram(self, partition, indent=""):
        """Vẽ Ferrers diagram"""
        for part in partition:
            print(indent + "* " * part)
    
    def format_partition(self, partition):
        """Format partition để hiển thị đẹp"""
        if not partition:
            return "{}"
        return "(" + ",".join(map(str, partition)) + ")"
    
    def solve_problem3(self, n, k):
        """
        Giải bài toán 3: Số phân hoạch tự liên hợp
        
        Args:
            n: Số cần phân hoạch
            k: Số phần
        """
        print("=== BÀI TOÁN 3: SỐ PHÂN HOẠCH TỰ LIÊN HỢP ===")
        print(f"Tham số: n = {n}, k = {k}\n")
        
        # (a) Đếm và in các phân hoạch tự liên hợp có k phần
        print(f"Phần (a): Đếm số phân hoạch tự liên hợp có {k} phần")
        self_conjugate_partitions = self.find_self_conjugate_partitions(n, k)
        print(f"p_selfcjg_{k}({n}) = {len(self_conjugate_partitions)}\n")
        
        print("Các phân hoạch tự liên hợp:")
        for i, partition in enumerate(self_conjugate_partitions):
            print(f"{i + 1}. λ = {self.format_partition(partition)}")
            print("   Ferrers Diagram:")
            self.draw_ferrers_diagram(partition, "   ")
            
            # Verify tính self-conjugate
            conjugate = self.compute_conjugate(partition)
            is_correct = (partition == conjugate)
            print(f"   Kiểm tra λ = λ^T: {'✓' if is_correct else '✗'}\n")
        
        # (b) Đếm số phân hoạch có số phần lẻ
        print("Phần (b): Đếm số phân hoạch có số phần lẻ")
        odd_parts_count = self.count_partitions_with_odd_parts(n)
        print(f"Số phân hoạch của {n} có số phần lẻ: {odd_parts_count}\n")
        
        # So sánh với định lý
        print("Định lý Euler: Số phân hoạch tự liên hợp = Số phân hoạch thành các phần lẻ khác nhau")
        distinct_odd_count = self.count_partitions_into_distinct_odd_parts(n)
        print(f"Số phân hoạch của {n} thành các phần lẻ khác nhau: {distinct_odd_count}\n")
        
        # (c) Thiết lập công thức truy hồi
        print("Phần (c): Thiết lập công thức truy hồi")
        print("Công thức: p_selfcjg_k(n) = p_selfcjg_k(n-1, k-1) + p_selfcjg_k(n-k, k)")
        print("Giải thích:")
        print("- p_selfcjg_k(n-1, k-1): Thêm phần mới có giá trị 1")
        print("- p_selfcjg_k(n-k, k): Tăng mỗi phần hiện có lên 1\n")
        
        # Implementation bằng đệ quy
        recursive_result = self.self_conjugate_recursive(n, k)
        print(f"Kết quả đệ quy (với memoization): {recursive_result}")
        
        # Implementation bằng DP
        dp_result = self.self_conjugate_dp(n, k)
        print(f"Kết quả quy hoạch động: {dp_result}")
        
        print(f"Kiểm tra tính đúng (đệ quy vs DP): {'✓' if recursive_result == dp_result else '✗'}\n")

def main():
    print("CHƯƠNG TRÌNH GIẢI BÀI TOÁN 3: SỐ PHÂN HOẠCH TỰ LIÊN HỢP")
    print("=" * 70 + "\n")
    
    try:
        n = int(input("Nhập n (số cần phân hoạch): "))
        k = int(input("Nhập k (số phần): "))
        print()
        
        # Kiểm tra tính hợp lệ
        if n <= 0 or k <= 0:
            print("Lỗi: n và k phải là số nguyên dương!")
            return
        
        solver = SelfConjugatePartitionSolver()
        solver.solve_problem3(n, k)
        
        # Demo với các test cases
        print("=" * 70)
        print("DEMO VỚI CÁC TEST CASES KHÁC:")
        print("=" * 70)
        
        test_cases = [(6, 3), (8, 4), (9, 3)]
        
        for n_test, k_test in test_cases:
            print()
            solver.solve_problem3(n_test, k_test)
            
    except ValueError:
        print("Lỗi: Vui lòng nhập số nguyên hợp lệ!")
    except Exception as e:
        print(f"Lỗi không mong muốn: {e}")

if __name__ == "__main__":
    main()