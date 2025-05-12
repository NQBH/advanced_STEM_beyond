import math

M = float(input("Nhập M > 0: "))

if M <= 0:
    print("M phải lớn hơn 0.")
else:
    N = math.floor(M ** 2 - 2) + 1
    print("N để sqrt(n + 2) > M là:", N)

    sqrt_value = math.sqrt(N + 2)
    print(f"Kiểm tra: sqrt({N} + 2) = {sqrt_value:.4f} > {M}")