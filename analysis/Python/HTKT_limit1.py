import math

epsilon = float(input("Nhập epsilon (ε > 0): "))

if epsilon <= 0:
    print("ε phải lớn hơn 0.")
else:
  
    N_epsilon = math.ceil(1.0 / epsilon - 1)
    print("Giá trị N_epsilon tối ưu là:", N_epsilon)