import os
import random

test_dir = "tests_1st_order_recurrence"
os.makedirs(test_dir, exist_ok=True)

MOD = 10**9 + 7

def solve(alpha, a, b, n):
    if n < 0:
        return "-1"
        
    # Chuẩn hóa modulo cho số âm
    alpha = (alpha % MOD + MOD) % MOD
    a = (a % MOD + MOD) % MOD
    b = (b % MOD + MOD) % MOD
    
    if n == 0:
        return str(alpha)

    # Dùng công thức toán học O(log n) để sinh test nhanh
    if a == 1:
        ans = (alpha + (n % MOD) * b) % MOD
    else:
        # a_n = a^n * alpha + b * (a^n - 1) / (a - 1)
        an = pow(a, n, MOD)
        # Nghịch đảo modulo của (a - 1) theo định lý Fermat nhỏ
        inv_a_minus_1 = pow(a - 1, MOD - 2, MOD)
        
        term1 = (an * alpha) % MOD
        term2 = (b * (an - 1) * inv_a_minus_1) % MOD
        ans = (term1 + term2) % MOD
        
    return str(ans)

def generate_tests():
    for i in range(1, 101):
        # 1. Edge Cases & Samples (Test 1-15)
        if i == 1: alpha, a, b, n = 0, 1, 1, 2       # Sample 1
        elif i == 2: alpha, a, b, n = 0, 1, 2, 2     # Sample 2
        elif i == 3: alpha, a, b, n = 1, 2, 1, 3     # Test truy hồi cơ bản
        elif i == 4: alpha, a, b, n = 5, 0, 10, 5    # a = 0
        elif i == 5: alpha, a, b, n = 5, 10, 0, 5    # b = 0
        elif i == 6: alpha, a, b, n = 10, 2, 3, 0    # n = 0
        elif i == 7: alpha, a, b, n = 10, 2, 3, -5   # n < 0
        elif i == 8: alpha, a, b, n = -5, -2, -3, 10 # Toàn số âm
        elif i == 9: alpha, a, b, n = 2*10**9, 2*10**9, 2*10**9, 10 # Test vượt MOD
        elif i == 10: alpha, a, b, n = 1, MOD + 1, 5, 10 # a đồng dư 1 theo MOD
        elif i <= 15:
            alpha = random.randint(-100, 100)
            a = random.randint(-100, 100)
            b = random.randint(-100, 100)
            n = random.randint(-10, 100)
            
        # 2. Dữ liệu nhỏ - Easy (Test 16-40)
        elif i <= 40:
            alpha = random.randint(-1000, 1000)
            a = random.randint(-1000, 1000)
            b = random.randint(-1000, 1000)
            n = random.randint(100, 5000)
            
        # 3. Dữ liệu trung bình - Medium (Test 41-70)
        elif i <= 70:
            alpha = random.randint(-10**6, 10**6)
            a = random.randint(-10**6, 10**6)
            b = random.randint(-10**6, 10**6)
            n = random.randint(10000, 500000)
            
        # 4. Dữ liệu cực lớn kịch giới hạn (Test 71-100)
        else:
            alpha = random.randint(-2*10**9, 2*10**9)
            a = random.randint(-2*10**9, 2*10**9)
            b = random.randint(-2*10**9, 2*10**9)
            n = random.randint(5*10**6, 10**7) # n lớn nhất 10^7
            
            # Đôi khi chèn test bẫy n = 0 ở các test khó
            if random.random() < 0.05:
                n = 0

        # Ghi file
        ans = solve(alpha, a, b, n)

        inp_filename = os.path.join(test_dir, f"{i}.inp")
        with open(inp_filename, 'w') as f_in:
            f_in.write(f"{alpha} {a} {b} {n}\n")

        out_filename = os.path.join(test_dir, f"{i}.out")
        with open(out_filename, 'w') as f_out:
            f_out.write(f"{ans}\n")

    print(f"Đã tạo thành công 100 bộ test trong thư mục '{test_dir}'!")

if __name__ == "__main__":
    generate_tests()