import math

epsilon = float(input("Nhập epsilon (ε > 0): "))

if epsilon <= 0:
    print("ε phải lớn hơn 0.")
else:
    n = 0
    while (n + 1) / (3 ** n) >= epsilon:
        n += 1
        if n > 1000:
            print("Không tìm thấy trong 1000 bước.")
            break
    else:
        print("Giá trị N_epsilon tối ưu là:", n)