import math
epsilon = float(input("Nhập epsilon (> 0): "))

if epsilon <= 0:
    print("Epsilon phải > 0.")
else:
    N_opt = math.ceil(math.log2(1 / epsilon))
    print(f"N_epsilon_opt = {N_opt}")