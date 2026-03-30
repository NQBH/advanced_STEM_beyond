import os
import random

test_dir = "tests_quadrilateral"
os.makedirs(test_dir, exist_ok=True)

def solve(a, b, c, d):
    # Kiểm tra số dương và bất đẳng thức tứ giác
    if a > 0 and b > 0 and c > 0 and d > 0:
        if 2 * max(a, b, c, d) < (a + b + c + d):
            return str(a + b + c + d)
    return "-1"

def generate_tests():
    for i in range(1, 101):
        a, b, c, d = 0, 0, 0, 0
        
        # 1. Sample Tests & Edge Cases (Test 1-15)
        if i == 1: edges = [1, 1, 1, 1]              # Sample 1
        elif i == 2: edges = [1, 1, 1, 2]            # Sample 2
        elif i == 3: edges = [1, 1, 1, 3]            # Sample 3
        elif i == 4: edges = [0, 5, 5, 5]            # Có số 0
        elif i == 5: edges = [-10, 20, 20, 20]       # Có số âm
        elif i == 6: edges = [0, 0, 0, 0]            # Tất cả bằng 0
        elif i == 7: edges = [10, 10, 10, 30]        # Tứ giác suy biến (2*max == sum)
        elif i == 8: edges = [2*10**9, 2*10**9, 2*10**9, 2*10**9] # Max hợp lệ (vượt int32)
        elif i == 9: edges = [2*10**9, 2*10**9, 2*10**9, 6*10**9] # Max không hợp lệ
        elif i == 10: edges = [1, 1, 1, 2*10**9]     # 3 cạnh cực nhỏ, 1 cạnh cực lớn
        elif i <= 15:
            # Random có dính số âm hoặc 0
            edges = [random.randint(-100, 100) for _ in range(4)]
            
        # 2. Dữ liệu nhỏ - Easy (Test 16-40)
        elif i <= 40:
            edges = [random.randint(1, 100) for _ in range(3)]
            if random.random() < 0.6: # 60% hợp lệ
                edges.append(random.randint(1, sum(edges) - 1))
            else: # 40% không hợp lệ
                edges.append(random.randint(sum(edges), sum(edges) + 50))
                
        # 3. Dữ liệu trung bình - Medium (Test 41-70)
        elif i <= 70:
            edges = [random.randint(1000, 10**5) for _ in range(3)]
            if random.random() < 0.6:
                edges.append(random.randint(1, sum(edges) - 1))
            else:
                edges.append(random.randint(sum(edges), sum(edges) + 10**5))
                
        # 4. Dữ liệu cực lớn gây Overflow int32 - Hard (Test 71-100)
        else:
            edges = [random.randint(5*10**8, 2*10**9) for _ in range(3)]
            if random.random() < 0.7: 
                # Hợp lệ: d < a + b + c và đảm bảo d <= 2*10^9
                max_d = min(2 * 10**9, sum(edges) - 1)
                edges.append(random.randint(1, max_d))
            else:
                # Không hợp lệ: mớm giá trị sao cho d >= a + b + c
                # Do a, b, c rất lớn nên sum có thể > 2*10^9, ta ép d = 2*10^9 và giảm a, b, c xuống
                edges = [random.randint(10**7, 5*10**8) for _ in range(3)]
                edges.append(random.randint(sum(edges), 2 * 10**9))

        # Xáo trộn vị trí để cạnh lớn nhất không cố định ở cuối
        random.shuffle(edges)
        a, b, c, d = edges

        # 3. Ghi ra file .inp và .out
        ans = solve(a, b, c, d)

        inp_filename = os.path.join(test_dir, f"{i}.inp")
        with open(inp_filename, 'w') as f_in:
            f_in.write(f"{a} {b} {c} {d}\n")

        out_filename = os.path.join(test_dir, f"{i}.out")
        with open(out_filename, 'w') as f_out:
            f_out.write(f"{ans}\n")

    print(f"Đã tạo thành công 100 bộ test trong thư mục '{test_dir}'!")

if __name__ == "__main__":
    generate_tests()