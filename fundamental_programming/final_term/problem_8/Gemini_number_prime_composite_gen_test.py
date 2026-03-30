import os
import random
import math

test_dir = "tests_number_prime_composite"
os.makedirs(test_dir, exist_ok=True)

# Khởi tạo các số nguyên tố cơ sở 1 lần để tái sử dụng sinh output nhanh
def get_base_primes(limit):
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    primes = []
    for p in range(2, limit + 1):
        if is_prime[p]:
            primes.append(p)
            for i in range(p * p, limit + 1, p):
                is_prime[i] = False
    return primes

BASE_LIMIT = int(math.sqrt(2 * 10**9)) + 1
BASE_PRIMES = get_base_primes(BASE_LIMIT)

def solve(a, b):
    # 1. Đếm số n (neither)
    upper_neither = min(b, 1)
    neither_count = max(0, upper_neither - a + 1)
    
    if b < 2:
        return f"0 0 {neither_count}"
        
    # 2. Sàng phân đoạn
    L = max(a, 2)
    R = b
    range_size = R - L + 1
    
    is_p = [True] * range_size
    
    for p in BASE_PRIMES:
        if p * p > R:
            break
        start = max(p * p, (L + p - 1) // p * p)
        for j in range(start, R + 1, p):
            is_p[j - L] = False
            
    prime_count = sum(is_p)
    composite_count = range_size - prime_count
    
    return f"{prime_count} {composite_count} {neither_count}"

def generate_tests():
    for i in range(1, 101):
        # 1. Edge Cases & Samples (Test 1-15)
        if i == 1: a, b = 1, 2               # Sample 1
        elif i == 2: a, b = 0, 3             # Sample 2
        elif i == 3: a, b = 0, 4             # Sample 3
        elif i == 4: a, b = -2, 5            # Sample 4
        elif i == 5: a, b = -10, -1          # Toàn số âm
        elif i == 6: a, b = 0, 1             # Chỉ có 0 và 1
        elif i == 7: a, b = 2, 2             # Chỉ có đúng 1 số nguyên tố nhỏ
        elif i == 8: a, b = -2000000000, -1999000000 # Max âm
        elif i <= 15:
            a = random.randint(-100, 50)
            b = random.randint(a, a + 100)
            
        # 2. Dữ liệu nhỏ - Easy (Test 16-40)
        elif i <= 40:
            a = random.randint(-5000, 50000)
            b = random.randint(a, min(55000, a + 10000))
            
        # 3. Dữ liệu trung bình - Medium (Test 41-70)
        elif i <= 70:
            a = random.randint(-10**6, 10**7)
            b = random.randint(a, a + random.randint(50000, 100000))
            
        # 4. Dữ liệu cực lớn tiệm cận Max Range - Hard (Test 71-100)
        else:
            length = random.randint(900000, 1000000) # Ép kịch trần độ dài 1 triệu
            strategy = random.randint(1, 3)
            
            if strategy == 1:
                # Vùng số cực lớn
                b = random.randint(10**9, 2*10**9)
                a = b - length
            elif strategy == 2:
                # Vùng cắt qua số 0
                a = random.randint(-800000, -100000)
                b = a + length
            else:
                # Kịch khung giới hạn tối đa
                b = 2000000000
                a = b - 1000000

        # Ghi file
        ans = solve(a, b)

        inp_filename = os.path.join(test_dir, f"{i}.inp")
        with open(inp_filename, 'w') as f_in:
            f_in.write(f"{a} {b}\n")

        out_filename = os.path.join(test_dir, f"{i}.out")
        with open(out_filename, 'w') as f_out:
            f_out.write(f"{ans}\n")

    print(f"Đã tạo thành công 100 bộ test trong thư mục '{test_dir}'!")

if __name__ == "__main__":
    generate_tests()