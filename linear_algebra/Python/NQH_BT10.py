print("Nhập các phần tử của ma trận A (dạng 2x2):")

a = float(input("Nhập a (hàng 1, cột 1): "))
b = float(input("Nhập b (hàng 1, cột 2): "))
c = float(input("Nhập c (hàng 2, cột 1): "))
d = float(input("Nhập d (hàng 2, cột 2): "))

det = a * d - b * c

print(f"\nĐịnh thức của ma trận A là: {det}")
