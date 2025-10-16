#Bài Tập 1: Kiểm tra xem có phải ma trận bổ sung
import numpy as np
m = int(input("Nhập số hàng: "))
n = int(input("Nhập số cột: "))
A = np.zeros((m,n))
for i in range(m):
    for j in range(n):
        A[i][j] = int(input(f"Nhập Phần Tử A[{i}][{j}]: "))
print(A)