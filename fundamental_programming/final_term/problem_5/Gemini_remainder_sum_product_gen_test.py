import os
import random

test_dir = "tests_sum_product"
os.makedirs(test_dir, exist_ok=True)

def solve(n, b, a):
    if b == 0:
        return "-1"
    
    sum_val = 0
    prod_val = 1 % b
    
    for x in a:
        sum_val = (sum_val + x) % b
        prod_val = (prod_val * x) % b
        
    return f"{sum_val} {prod_val}"

def generate_tests():
    for i in range(1, 101):
        # 1. Edge Cases & Samples (Test 1-15)
        if i == 1: n, b, a = 1, 0, [1]
        elif i == 2: n, b, a = 2, 1, [1, 2]
        elif i == 3: n, b, a = 3, 2, [1, -3, 5]
        elif i == 4: n, b, a = 5, 0, [-1, -2, -3, -4, -5] # b = 0 với số âm
        elif i == 5: n, b, a = 1, 10, [-5]                # 1 phần tử âm
        elif i == 6: n, b, a = 5, 5, [-10, -5, 0, 5, 10]  # Các số là bội của b
        elif i == 7: n, b, a = 2 * 10**5, 0, [1] * (2 * 10**5) # b = 0 mảng cực lớn
        elif i <= 15:
            n = random.randint(1, 10)
            b = random.randint(1, 20)
            a = [random.randint(-20, 20) for _ in range(n)]
            
        # 2. Dữ liệu nhỏ - Easy (Test 16-40)
        elif i <= 40:
            n = random.randint(10, 1000)
            b = random.randint(1, 1000)
            a = [random.randint(-1000, 1000) for _ in range(n)]
            
        # 3. Dữ liệu trung bình - Medium (Test 41-70)
        elif i <= 70:
            n = random.randint(1000, 50000)
            b = random.randint(1, 100000)
            a = [random.randint(-100000, 100000) for _ in range(n)]
            
        # 4. Dữ liệu cực lớn bứt giới hạn thời gian chạy - Hard (Test 71-100)
        else:
            # Test 95-100 sẽ ép lên kịch trần 2*10^5
            if i >= 95:
                n = 200000
                b = 200000 if i % 2 == 0 else random.randint(100000, 200000)
            else:
                n = random.randint(150000, 200000)
                b = random.randint(100000, 200000)
                
            a = [random.randint(-200000, 200000) for _ in range(n)]

        # Ghi file
        ans = solve(n, b, a)

        inp_filename = os.path.join(test_dir, f"{i}.inp")
        with open(inp_filename, 'w') as f_in:
            f_in.write(f"{n} {b}\n")
            # Nối mảng bằng dấu cách để in ra file
            f_in.write(" ".join(map(str, a)) + "\n")

        out_filename = os.path.join(test_dir, f"{i}.out")
        with open(out_filename, 'w') as f_out:
            f_out.write(f"{ans}\n")

    print(f"Đã tạo thành công 100 bộ test trong thư mục '{test_dir}'!")

if __name__ == "__main__":
    generate_tests()