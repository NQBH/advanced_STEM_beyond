def find_N_opt(epsilon):
    n = 1
    while 1 / (2 ** n) >= epsilon:
        n += 1
    return n

epsilon = float(input("Nhập giá trị epsilon (> 0): "))
if epsilon <= 0:
    print("Epsilon phải lớn hơn 0!")
else:
    N_opt = find_N_opt(epsilon)
    print(f"Giá trị nhỏ nhất N sao cho 1/2^N < ε là: N = {N_opt}")