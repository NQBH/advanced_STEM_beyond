import numpy as np
n = int(input("Nhập số hàng: "))
m = int(input("Nhập số cột: "))
A = np.zeros((n,m))
for i in range (n):
    for j in range(m):
        A[i][j] = int(input(f"Nhập phần tử A[{i}][{j}]: "))
print(A)
