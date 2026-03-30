import os
import random

test_dir = "tests_prime_composite"
os.makedirs(test_dir, exist_ok=True)

def is_prime(n):
    if n < 2: return False
    if n in (2, 3): return True
    if n % 2 == 0 or n % 3 == 0: return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def solve(n):
    if n < 2:
        return "none"
    elif is_prime(n):
        return "prime"
    else:
        return "composite"

def generate_tests():
    # Danh sách một vài số nguyên tố lớn biết trước để làm test case
    large_primes = [1999999973, 1000000007, 1000000009, 1999999927, 1999999943]
    
    for i in range(1, 101):
        # 1. Edge Cases & Samples (Test 1-15)
        if i == 1: n = -2
        elif i == 2: n = 1
        elif i == 3: n = 2
        elif i == 4: n = 4
        elif i == 5: n = 0
        elif i == 6: n = 3
        elif i == 7: n = -2000000000  # Biên âm
        elif i <= 15:
            n = random.randint(-100, 100)
            
        # 2. Dữ liệu nhỏ - Easy (Test 16-40)
        elif i <= 40:
            n = random.randint(2, 10000)
            
        # 3. Dữ liệu trung bình - Medium (Test 41-70)
        elif i <= 70:
            n = random.randint(10000, 10**7)
            
        # 4. Dữ liệu lớn (Test 71-100)
        else:
            strategy = random.randint(1, 4)
            if strategy == 1:
                # Đưa số nguyên tố lớn vào
                n = random.choice(large_primes)
            elif strategy == 2:
                # Hợp số siêu khó: Tích của 2 số nguyên tố tiệm cận căn bậc 2 của 2*10^9
                # Căn(2*10^9) ~ 44721. Ta lấy 2 số nguyên tố quanh vùng này.
                p1 = 44711 
                p2 = 44729
                n = p1 * p2 # = 1999878319
            elif strategy == 3:
                # Max biên độ
                n = 2000000000
            else:
                # Số lớn ngẫu nhiên
                n = random.randint(10**9, 2*10**9)

        # Ghi file
        ans = solve(n)

        inp_filename = os.path.join(test_dir, f"{i}.inp")
        with open(inp_filename, 'w') as f_in:
            f_in.write(f"{n}\n")

        out_filename = os.path.join(test_dir, f"{i}.out")
        with open(out_filename, 'w') as f_out:
            f_out.write(f"{ans}\n")

    print(f"Đã tạo thành công 100 bộ test trong thư mục '{test_dir}'!")

if __name__ == "__main__":
    generate_tests()