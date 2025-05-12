#Cau B
import math
epsilon = float(input("Nhập epsilon (số thực dương): "))
n_opt = math.ceil(math.log2(1 / epsilon))
print(f"\nGiá trị N_epsilon_opt nhỏ nhất sao cho 1/2^n < epsilon là: {n_opt}")