import os
import random

# Tạo thư mục chứa test
test_dir = "tests_triangle"
os.makedirs(test_dir, exist_ok=True)

def solve(a, b, c):
    if a > 0 and b > 0 and c > 0 and a < b + c and b < a + c and c < a + b:
        return str(a + b + c)
    return "-1"

def generate_tests():
    for i in range(1, 101):
        a, b, c = 0, 0, 0
        
        # 1. Phân bổ độ khó và Edge Cases (Test 1-15)
        if i == 1: a, b, c = 1, 1, 0           # Sample 1
        elif i == 2: a, b, c = -1, 1, 1        # Sample 2
        elif i == 3: a, b, c = 1, 1, 1         # Sample 3
        elif i == 4: a, b, c = 0, 0, 0         # Cả 3 bằng 0
        elif i == 5: a, b, c = 3, 4, 7         # Tam giác suy biến (a + b = c)
        elif i == 6: a, b, c = -10, -10, -10   # Cả 3 số âm
        elif i == 7: a, b, c = 2*10**9, 2*10**9, 2*10**9 # Max giới hạn (vượt int32)
        elif i == 8: a, b, c = 2*10**9, 2*10**9, 1       # Tam giác cân cực lớn
        elif i == 9: a, b, c = 10**9, 10**9, 2*10**9     # Cạnh lớn nhất bằng tổng 2 cạnh kia
        elif i <= 15:
            # Random có số âm hoặc 0
            a = random.randint(-100, 100)
            b = random.randint(-100, 100)
            c = random.randint(-100, 100)
            
        # 2. Dữ liệu nhỏ - Easy (Test 16-40)
        elif i <= 40:
            if random.random() < 0.6: # 60% tạo tam giác hợp lệ
                a = random.randint(1, 100)
                b = random.randint(1, 100)
                c = random.randint(abs(a-b) + 1, a + b - 1) 
            else: # 40% không hợp lệ
                a = random.randint(1, 100)
                b = random.randint(1, 100)
                c = random.randint(a + b, a + b + 50)
                
        # 3. Dữ liệu trung bình - Medium (Test 41-70)
        elif i <= 70:
            if random.random() < 0.6:
                a = random.randint(1000, 10**5)
                b = random.randint(1000, 10**5)
                c = random.randint(abs(a-b) + 1, a + b - 1)
            else:
                a = random.randint(1000, 10**5)
                b = random.randint(1000, 10**5)
                c = random.randint(a + b, a + b + 10**5)
                
        # 4. Dữ liệu cực lớn gây Overflow int32 - Hard (Test 71-100)
        else:
            if random.random() < 0.7: # 70% tạo tam giác hợp lệ để test tính chu vi
                a = random.randint(10**9, 2*10**9)
                b = random.randint(10**9, 2*10**9)
                # Đảm bảo c <= 2*10^9 theo đúng giới hạn đề bài
                max_c = min(2 * 10**9, a + b - 1)
                c = random.randint(abs(a-b) + 1, max_c)
            else:
                a = random.randint(10**8, 10**9)
                b = random.randint(10**8, 10**9)
                c = random.randint(a + b, 2 * 10**9)

        # Xáo trộn vị trí a, b, c để test case tự nhiên hơn
        edges = [a, b, c]
        random.shuffle(edges)
        a, b, c = edges

        # 3. Ghi ra file .inp và .out
        ans = solve(a, b, c)

        inp_filename = os.path.join(test_dir, f"{i}.inp")
        with open(inp_filename, 'w') as f_in:
            f_in.write(f"{a} {b} {c}\n")

        out_filename = os.path.join(test_dir, f"{i}.out")
        with open(out_filename, 'w') as f_out:
            f_out.write(f"{ans}\n")

    print(f"Đã tạo thành công 100 bộ test trong thư mục '{test_dir}'!")

if __name__ == "__main__":
    generate_tests()