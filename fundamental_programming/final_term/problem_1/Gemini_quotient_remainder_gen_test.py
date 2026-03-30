import os
import random

# Tạo thư mục chứa test nếu chưa có
test_dir = "tests"
os.makedirs(test_dir, exist_ok=True)

def solve(a, b):
    if b == 0:
        return "-1"
    # Trong Python, phép % và // với số âm đã trả về đúng chuẩn toán học (r >= 0)
    return f"{a // b} {a % b}"

def generate_tests():
    for i in range(1, 101):
        # 1. Phân bổ độ khó
        if i <= 10:
            # Edge cases & test nhỏ thủ công
            if i == 1: a, b = 1, 0
            elif i == 2: a, b = 1, 2
            elif i == 3: a, b = -2, 1
            elif i == 4: a, b = 0, 5
            elif i == 5: a, b = 0, 0
            elif i == 6: a, b = -5, 3
            elif i == 7: a, b = -10, 10
            elif i == 8: a, b = 10, 10
            elif i == 9: a, b = 2 * 10**9, 0
            else: a, b = -2 * 10**9, 1
        elif i <= 40:
            # Dữ liệu nhỏ (Easy)
            a = random.randint(-100, 100)
            b = random.randint(0, 100)
        elif i <= 70:
            # Dữ liệu trung bình (Medium)
            a = random.randint(-10**5, 10**5)
            b = random.randint(0, 10**5)
        else:
            # Dữ liệu cực lớn (Hard)
            a = random.randint(-2 * 10**9, 2 * 10**9)
            b = random.randint(0, 2 * 10**9)

        # 2. Sinh kết quả
        ans = solve(a, b)

        # 3. Ghi ra file .inp
        inp_filename = os.path.join(test_dir, f"{i}.inp")
        with open(inp_filename, 'w') as f_in:
            f_in.write(f"{a} {b}\n")

        # 4. Ghi ra file .out
        out_filename = os.path.join(test_dir, f"{i}.out")
        with open(out_filename, 'w') as f_out:
            f_out.write(f"{ans}\n")

    print("Đã tạo thành công 100 bộ test trong thư mục 'tests'!")

if __name__ == "__main__":
    generate_tests()