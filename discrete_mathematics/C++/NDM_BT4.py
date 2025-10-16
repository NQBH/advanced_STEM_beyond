import math

n = float(input("Nhap n: "))

# Kiểm tra bất đẳng thức 2^n >= 100
if math.pow(2, n) >= 100:
    print("Dung")
else:
    print("Sai")