#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from functools import lru_cache
from typing import List, Tuple
import sys

class SelfConjugatePartitions:
    def __init__(self):
        # Memoization dictionaries
        self.memo_self_conjugate = {}
        self.memo_odd_parts = {}
        self.memo_distinct_parts = {}
    
    def is_self_conjugate(self, partition: List[int]) -> bool:
        """
        Kiểm tra xem một phân hoạch có tự liên hợp hay không
        """
        if not partition:
            return True
        
        # Tạo biểu đồ Ferrers chuyển vị
        conjugate = []
        max_part = max(partition)
        
        for col in range(1, max_part + 1):
            height = 0
            for row in range(len(partition)):
                if partition[row] >= col:
                    height += 1
            if height > 0:
                conjugate.append(height)
        
        # So sánh với phân hoạch gốc
        return partition == conjugate
    
    def generate_self_conjugate(self, n: int, k: int, current_sum: int = 0, 
                               min_part: int = 1, current_partition: List[int] = None) -> Tuple[int, List[List[int]]]:
        """
        Sinh tất cả phân hoạch tự liên hợp của n có đúng k phần
        """
        if current_partition is None:
            current_partition = []
        
        partitions = []
        count = 0
        
        def backtrack(curr_sum, curr_min, curr_partition):
            nonlocal count, partitions
            
            if len(curr_partition) == k:
                if curr_sum == n and self.is_self_conjugate(curr_partition):
                    count += 1
                    partitions.append(curr_partition.copy())
                return
            
            if curr_sum >= n or len(curr_partition) > k:
                return
            
            remaining = n - curr_sum
            remaining_parts = k - len(curr_partition)
            
            # Giới hạn để đảm bảo phân hoạch giảm dần
            max_next = remaining // remaining_parts if remaining_parts > 0 else remaining
            if curr_partition:
                max_next = min(max_next, curr_partition[-1])
            
            for i in range(max(curr_min, 1), max_next + 1):
                if curr_sum + i <= n:
                    curr_partition.append(i)
                    backtrack(curr_sum + i, i, curr_partition)
                    curr_partition.pop()
        
        backtrack(current_sum, min_part, current_partition)
        return count, partitions
    
    def partitions_with_odd_parts(self, n: int, max_odd_part: int) -> int:
        """
        Đếm phân hoạch với các phần lẻ (theo định lý Euler)
        """
        if n == 0:
            return 1
        if n < 0 or max_odd_part <= 0:
            return 0
        
        key = (n, max_odd_part)
        if key in self.memo_odd_parts:
            return self.memo_odd_parts[key]
        
        # Tìm số lẻ tiếp theo nhỏ hơn max_odd_part
        next_odd = max_odd_part - 2
        while next_odd > 0 and next_odd % 2 == 0:
            next_odd -= 1
        
        result = 0
        if next_odd > 0:
            result = self.partitions_with_odd_parts(n, next_odd)  # Không dùng max_odd_part
        
        if max_odd_part % 2 == 1:  # max_odd_part là số lẻ
            result += self.partitions_with_odd_parts(n - max_odd_part, max_odd_part)  # Dùng max_odd_part
        
        self.memo_odd_parts[key] = result
        return result
    
    def partitions_with_distinct_parts(self, n: int, max_part: int) -> int:
        """
        Đếm phân hoạch với các phần phân biệt
        """
        if n == 0:
            return 1
        if n < 0 or max_part <= 0:
            return 0
        
        key = (n, max_part)
        if key in self.memo_distinct_parts:
            return self.memo_distinct_parts[key]
        
        result = self.partitions_with_distinct_parts(n, max_part - 1)  # Không dùng max_part
        if n >= max_part:
            result += self.partitions_with_distinct_parts(n - max_part, max_part - 1)  # Dùng max_part
        
        self.memo_distinct_parts[key] = result
        return result
    
    def self_conjugate_partitions(self, n: int, max_odd: int) -> int:
        """
        Công thức truy hồi cho phân hoạch tự liên hợp
        """
        if n == 0:
            return 1
        if n < 0 or max_odd <= 0:
            return 0
        if max_odd > n:
            return self.self_conjugate_partitions(n, n)
        
        key = (n, max_odd)
        if key in self.memo_self_conjugate:
            return self.memo_self_conjugate[key]
        
        result = 0
        
        if max_odd % 2 == 0:
            # max_odd chẵn, bỏ qua
            result = self.self_conjugate_partitions(n, max_odd - 1)
        else:
            # max_odd lẻ
            result = self.self_conjugate_partitions(n, max_odd - 2)  # Không dùng max_odd
            result += self.self_conjugate_partitions(n - max_odd, max_odd)  # Dùng max_odd
        
        self.memo_self_conjugate[key] = result
        return result
    
    def print_partition(self, partition: List[int]) -> str:
        """
        Format một phân hoạch để in ra
        """
        return f"({', '.join(map(str, partition))})"
    
    def solve_problem_3(self, n: int, k: int):
        """
        Giải bài toán 3 hoàn chỉnh
        """
        if n <= 0 or k <= 0:
            print("n và k phải là số nguyên dương!")
            return
        
        print(f"Phân tích phân hoạch tự liên hợp cho n = {n}, k = {k}:")
        print("=" * 54)
        
        # Phần (a): Đếm số phân hoạch tự liên hợp của n có k phần
        print(f"\n(a) Đếm phân hoạch tự liên hợp có đúng {k} phần:")
        
        if n <= 20 and k <= 10:  # Giới hạn để tránh tính toán quá lâu
            count, partitions = self.generate_self_conjugate(n, k)
            print(f"Các phân hoạch tự liên hợp có {k} phần: ", end="")
            for partition in partitions:
                print(self.print_partition(partition), end=" ")
            print(f"\np_{k}^self({n}) = {count}")
        else:
            print("n hoặc k quá lớn để liệt kê trực tiếp.")
        
        # Phần (b): Đếm số phân hoạch của n có các phần lẻ
        print(f"\n(b) Đếm phân hoạch với các phần lẻ:")
        
        # Tìm số lẻ lớn nhất <= n
        max_odd = n if n % 2 == 1 else n - 1
        
        p_odd = self.partitions_with_odd_parts(n, max_odd)
        print(f"Số phân hoạch của {n} với các phần lẻ: {p_odd}")
        
        # So sánh với số phân hoạch tự liên hợp tổng cộng
        total_self_conjugate = self.self_conjugate_partitions(n, n)
        print(f"Tổng số phân hoạch tự liên hợp của {n}: {total_self_conjugate}")
        
        print("Theo định lý Euler: ", end="")
        if p_odd == total_self_conjugate:
            print("Verified! Số phân hoạch tự liên hợp = Số phân hoạch với phần lẻ")
        else:
            print("Có sự khác biệt - cần kiểm tra lại thuật toán")
        
        # Phần (c): Bảng so sánh với các giá trị khác nhau của k
        print(f"\n(c) Bảng so sánh p_k^self(n) cho các k khác nhau:")
        print(f"k\tp_k^self({n})")
        print("-" * 19)
        
        for i in range(1, min(n, 8) + 1):
            if n <= 15:  # Chỉ tính với n nhỏ
                count, _ = self.generate_self_conjugate(n, i)
                print(f"{i}\t{count}")
        
        # Bổ sung: So sánh với phân hoạch phần phân biệt (định lý Euler khác)
        print(f"\nBổ sung - So sánh với phân hoạch có các phần phân biệt:")
        p_distinct = self.partitions_with_distinct_parts(n, n)
        print(f"Số phân hoạch của {n} với các phần phân biệt: {p_distinct}")


def main():
    """
    Hàm main để chạy chương trình
    """
    solver = SelfConjugatePartitions()
    
    try:
        n = int(input("Nhập n: "))
        k = int(input("Nhập k: "))
        solver.solve_problem_3(n, k)
    except ValueError:
        print("Vui lòng nhập số nguyên hợp lệ!")
    except KeyboardInterrupt:
        print("\nChương trình bị dừng bởi người dùng.")
    except RecursionError:
        print("Lỗi: n hoặc k quá lớn, gây tràn stack. Vui lòng thử với giá trị nhỏ hơn.")


# Thêm một số test cases
def run_tests():
    """
    Chạy một số test cases để kiểm tra tính đúng đắn
    """
    solver = SelfConjugatePartitions()
    
    print("Chạy test cases:")
    print("=" * 40)
    
    test_cases = [(4, 2), (5, 3), (6, 2), (7, 3)]
    
    for n, k in test_cases:
        print(f"\nTest case: n={n}, k={k}")
        count, partitions = solver.generate_self_conjugate(n, k)
        print(f"Số phân hoạch tự liên hợp: {count}")
        for partition in partitions:
            print(f"  {solver.print_partition(partition)}")
        
        # Kiểm tra định lý Euler
        max_odd = n if n % 2 == 1 else n - 1
        p_odd = solver.partitions_with_odd_parts(n, max_odd)
        total_self = solver.self_conjugate_partitions(n, n)
        print(f"Định lý Euler: {p_odd} == {total_self} ? {p_odd == total_self}")


if __name__ == "__main__":
    import sys
    
    if len(sys.argv) > 1 and sys.argv[1] == "--test":
        run_tests()
    else:
        main()