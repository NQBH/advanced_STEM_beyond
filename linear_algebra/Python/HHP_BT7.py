import numpy as np

# Nhập kích thước ma trận
m = int(input("Nhập số hàng của ma trận A: "))
n = int(input("Nhập số cột của ma trận A: "))

# Nhập các phần tử của ma trận
A = np.zeros((m, n), dtype=float)
for i in range(m):
    for j in range(n):
        A[i][j] = float(input(f"Nhập phần tử A[{i}][{j}]: "))
print("Ma trận ban đầu")
print(A)

# Menu
print("\nChọn phép biến đổi sơ cấp trên hàng:")
print("1. Đổi chỗ hai hàng")
print("2. Nhân một hàng với một số khác 0")
print("3. Cộng một bội của hàng này vào hàng khác")

choice  = int(input("Nhập lựa chọn 1/2/3: "))
if choice == 1:
    r1 = int(input("Nhập hàng 1: "))
    r2 = int(input("Nhập hàng 2: "))
    A[[r1,r2 ]] = A[[r2,r1]]
elif choice == 2:
    r = int(input("Nhập hàng cần nhân: "))
    k = float(input("Nhập một số k khác 0: "))
    A[r]=A[r]*k
elif choice == 3:
    r1 = int(input("Nhập hàng bị thay đổi: "))
    r2 = int(input("Nhập hàng dùng để cộng: "))
    k = float(input("Nhập một số K(r1 = r1 + k * r2) khác 0: "))
    A[r1] = A[r1] + k*A[r2]
else:
    print("lựa chọn không hợp lệ!!!")
print("Ma Trận Sau Khi Biến Đổi")
print (A)
