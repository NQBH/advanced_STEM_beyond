import os
import random

test_dir = "tests_2nd_order_recurrence"
os.makedirs(test_dir, exist_ok=True)

MOD = 10**9 + 7

# Hàm nhân 2 ma trận 3x3
def mat_mul(A, B):
    return [[sum(A[i][k] * B[k][j] for k in range(3)) % MOD for j in range(3)] for i in range(3)]

# Hàm lũy thừa ma trận O(log n)
def mat_pow(A, p):
    res = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    base = A
    while p > 0:
        if p % 2 == 1:
            res = mat_mul(res, base)
        base = mat_mul(base, base)
        p //= 2
    return res

# Hàm nhân ma trận 3x3 với vector cột 3x1
def vec_mul(A, V):
    return [sum(A[i][k] * V[k] for k in range(3)) % MOD for i in range(3)]

def solve(alpha, beta, a, b, c, n):
    if n < 0:
        return "-1"
        
    # Chuẩn hóa modulo cho số âm
    alpha = (alpha % MOD + MOD) % MOD
    beta = (beta % MOD + MOD) % MOD
    a = (a % MOD + MOD) % MOD
    b = (b % MOD + MOD) % MOD
    c = (c % MOD + MOD) % MOD
    
    if n == 0: return str(alpha)
    if n == 1: return str(beta)
    
    # Ma trận chuyển đổi T
    T = [
        [a, b, c],
        [1, 0, 0],
        [0, 0, 1]
    ]
    
    # Tính T^n và nhân với vector giá trị khởi tạo
    Tn = mat_pow(T, n)
    V_init = [beta, alpha, 1]
    V_final = vec_mul(Tn, V_init)
    
    # V_final[1] chính là giá trị của a_n
    return str(V_final[1])

def generate_tests():
    for i in range(1, 101):
        # 1. Edge Cases & Samples (Test 1-15)
        # Sửa lại Sample theo đúng logic a_n của đề bài
        if i == 1: alpha, beta, a, b, c, n = 0, 0, 1, 1, 1, 1       
        elif i == 2: alpha, beta, a, b, c, n = 0, 0, 1, 1, 1, 2     
        elif i == 3: alpha, beta, a, b, c, n = 1, 2, 3, 4, 5, 3     
        elif i == 4: alpha, beta, a, b, c, n = 10, 20, 0, 0, 5, 10   # a = 0, b = 0
        elif i == 5: alpha, beta, a, b, c, n = 10, 20, 2, 0, 5, 10   # b = 0
        elif i == 6: alpha, beta, a, b, c, n = 10, 20, 2, 3, 0, 10   # c = 0
        elif i == 7: alpha, beta, a, b, c, n = 10, 20, 3, 4, 5, 0    # n = 0
        elif i == 8: alpha, beta, a, b, c, n = 10, 20, 3, 4, 5, -5   # n < 0
        elif i == 9: alpha, beta, a, b, c, n = -5, -2, -3, -4, -1, 10 # Toàn số âm
        elif i <= 15:
            alpha = random.randint(-100, 100)
            beta = random.randint(-100, 100)
            a = random.randint(-100, 100)
            b = random.randint(-100, 100)
            c = random.randint(-100, 100)
            n = random.randint(-10, 100)
            
        # 2. Dữ liệu nhỏ (Test 16-40)
        elif i <= 40:
            alpha = random.randint(-1000, 1000)
            beta = random.randint(-1000, 1000)
            a = random.randint(-1000, 1000)
            b = random.randint(-1000, 1000)
            c = random.randint(-1000, 1000)
            n = random.randint(100, 5000)
            
        # 3. Dữ liệu trung bình (Test 41-70)
        elif i <= 70:
            alpha = random.randint(-10**6, 10**6)
            beta = random.randint(-10**6, 10**6)
            a = random.randint(-10**6, 10**6)
            b = random.randint(-10**6, 10**6)
            c = random.randint(-10**6, 10**6)
            n = random.randint(10000, 500000)
            
        # 4. Dữ liệu cực lớn kịch trần biên độ (Test 71-100)
        else:
            alpha = random.randint(-2*10**9, 2*10**9)
            beta = random.randint(-2*10**9, 2*10**9)
            a = random.randint(-2*10**9, 2*10**9)
            b = random.randint(-2*10**9, 2*10**9)
            c = random.randint(-2*10**9, 2*10**9)
            n = random.randint(5*10**6, 10**7) # n lớn nhất 10^7

        # Ghi file
        ans = solve(alpha, beta, a, b, c, n)

        inp_filename = os.path.join(test_dir, f"{i}.inp")
        with open(inp_filename, 'w') as f_in:
            f_in.write(f"{alpha} {beta} {a} {b} {c} {n}\n")

        out_filename = os.path.join(test_dir, f"{i}.out")
        with open(out_filename, 'w') as f_out:
            f_out.write(f"{ans}\n")

    print(f"Đã tạo thành công 100 bộ test trong thư mục '{test_dir}'!")

if __name__ == "__main__":
    generate_tests()