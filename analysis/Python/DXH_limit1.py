import math

def tim_N_epsilon():
    try:
        epsilon = float(input("Nhập epsilon (ε > 0): "))
        if epsilon <= 0:
            print("ε phải lớn hơn 0.")
            return

        N_eps = math.ceil(1.0 / epsilon - 1)
        print(f"Giá trị N_epsilon tối ưu là: {N_eps}")
    except ValueError:
        print("Vui lòng nhập một số thực hợp lệ.")

# Gọi hàm
tim_N_epsilon()