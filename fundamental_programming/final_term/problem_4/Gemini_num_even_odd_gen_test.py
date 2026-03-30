import os
import random

test_dir = "tests_even_odd"
os.makedirs(test_dir, exist_ok=True)

def solve(a, b):
    if a > b:
        a, b = b, a
        
    n = b - a + 1
    evens = n // 2
    odds = n // 2
    
    if n % 2 != 0:
        # Python xử lý a % 2 == 1 chuẩn xác cho cả số âm
        if a % 2 != 0:
            odds += 1
        else:
            evens += 1
            
    return f"{evens} {odds}"

def generate_tests():
    for i in range(1, 101):
        # 1. Edge Cases & Samples (Test 1-15)
        if i == 1: a, b = 0, 1                # Sample 1 (Chẵn lẻ)
        elif i == 2: a, b = -1, 1             # Sample 2 (Lẻ lẻ)
        elif i == 3: a, b = -1, 2             # Sample 3
        elif i == 4: a, b = 0, 0              # Đoạn 1 phần tử (Chẵn)
        elif i == 5: a, b = 1, 1              # Đoạn 1 phần tử (Lẻ)
        elif i == 6: a, b = -2, -2            # Âm 1 phần tử
        elif i == 7: a, b = 10, -10           # Bẫy a > b
        elif i == 8: a, b = -2*10**9, 2*10**9 # Max giới hạn cực đại
        elif i == 9: a, b = -2*10**9, -2*10**9 + 1
        elif i == 10: a, b = 2*10**9 - 1, 2*10**9
        elif i <= 15:
            # Ngẫu nhiên đoạn nhỏ xoay quanh số 0
            a = random.randint(-10, 10)
            b = random.randint(-10, 10)
            
        # 2. Dữ liệu nhỏ (Test 16-40)
        elif i <= 40:
            a = random.randint(-1000, 1000)
            b = random.randint(a, a + 5000)
            
        # 3. Dữ liệu trung bình (Test 41-70)
        elif i <= 70:
            a = random.randint(-10**7, 10**7)
            b = random.randint(a, a + 10**7)
            
        # 4. Dữ liệu lớn - Cố tình ép sinh viên phải dùng kiểu 64-bit (Test 71-100)
        else:
            # a rất âm, b rất dương để khoảng cách lớn hơn 2.14 tỷ
            a = random.randint(-2 * 10**9, -10**9)
            b = random.randint(10**9, 2 * 10**9)
            
            # Đôi khi lật ngược a và b để test bẫy a > b
            if random.random() < 0.2:
                a, b = b, a

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