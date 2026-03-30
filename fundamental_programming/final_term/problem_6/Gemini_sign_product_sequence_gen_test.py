import os
import random

test_dir = "tests_sign_product"
os.makedirs(test_dir, exist_ok=True)

def solve(a):
    if 0 in a:
        return "0"
    
    # Đếm số lượng số âm trong mảng
    neg_count = sum(1 for x in a if x < 0)
    
    if neg_count % 2 != 0:
        return "-1"
    return "1"

def generate_tests():
    for i in range(1, 101):
        # 1. Edge Cases & Samples (Test 1-15)
        if i == 1: n, a = 3, [0, 1, 2]
        elif i == 2: n, a = 4, [-1, -2, -3, 4]
        elif i == 3: n, a = 1, [0]
        elif i == 4: n, a = 1, [-2000000000]
        elif i == 5: n, a = 1, [2000000000]
        elif i == 6: n, a = 5, [-1, -1, -1, -1, -1]       # Lẻ số âm
        elif i == 7: n, a = 6, [-1, -1, -1, -1, -1, -1]   # Chẵn số âm
        elif i == 8: n, a = 10, [2000000000] * 10         # Toàn số dương cực lớn
        elif i == 9: n, a = 10, [-2000000000] * 10        # Toàn số âm cực lớn
        elif i <= 15:
            n = random.randint(10, 50)
            a = [random.randint(-100, 100) for _ in range(n)]
            
        # 2. Dữ liệu nhỏ - Easy (Test 16-40)
        elif i <= 40:
            n = random.randint(100, 5000)
            # 20% khả năng nhồi số 0 vào để bẫy
            has_zero = random.random() < 0.2
            a = []
            for _ in range(n):
                val = random.randint(-10000, 10000)
                if not has_zero and val == 0:
                    val = 1 # Né số 0 nếu không muốn chèn
                a.append(val)
            if has_zero:
                # Ép một vị trí ngẫu nhiên thành 0
                a[random.randint(0, n-1)] = 0
                
        # 3. Dữ liệu trung bình - Medium (Test 41-70)
        elif i <= 70:
            n = random.randint(10000, 50000)
            has_zero = random.random() < 0.1
            a = []
            for _ in range(n):
                val = random.randint(-10**9, 10**9)
                if not has_zero and val == 0:
                    val = -1
                a.append(val)
            if has_zero:
                a[random.randint(0, n-1)] = 0
                
        # 4. Dữ liệu lớn kích trần N và trị số (Test 71-100)
        else:
            n = random.randint(180000, 200000)
            
            # Phân bổ chiến thuật chèn mảng:
            strategy = random.randint(1, 4)
            if strategy == 1:
                # Gần như toàn số âm lớn
                a = [random.randint(-2*10**9, -1) for _ in range(n)]
            elif strategy == 2:
                # Toàn dương lớn
                a = [random.randint(1, 2*10**9) for _ in range(n)]
            elif strategy == 3:
                # Ngẫu nhiên đều
                a = [random.randint(-2*10**9, 2*10**9) for _ in range(n)]
                # Dọn sạch số 0 để test chẵn/lẻ số âm
                a = [x if x != 0 else 1 for x in a]
            else:
                # Bẫy chỉ đúng 1 số 0 nằm ở tít cuối mảng
                a = [random.randint(1, 2*10**9) for _ in range(n-1)]
                a.append(0)

        # Ghi file
        ans = solve(a)

        inp_filename = os.path.join(test_dir, f"{i}.inp")
        with open(inp_filename, 'w') as f_in:
            f_in.write(f"{n}\n")
            f_in.write(" ".join(map(str, a)) + "\n")

        out_filename = os.path.join(test_dir, f"{i}.out")
        with open(out_filename, 'w') as f_out:
            f_out.write(f"{ans}\n")

    print(f"Đã tạo thành công 100 bộ test trong thư mục '{test_dir}'!")

if __name__ == "__main__":
    generate_tests()