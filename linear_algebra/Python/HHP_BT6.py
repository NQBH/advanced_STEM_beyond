#Bài Tập 1: Kiểm tra xem có phải ma trận bổ su
import numpy as np
m = int(input("Nhập số hàng: "))
n = int(input("Nhập số cột: "))
A = np.zeros((m,n))
for i in range(m):
    for j in range(n):
        A[i][j] = int(input(f"Nhập Phần Tử A[{i}][{j}]: "))
print(A)
a = int(input("Nhập Số phần tử của vector: "))
B = np.zeros((1,a))
for i in range (a):
    B[0][i] = int(input(f"Nhập phần tử B[{i}]: "))


print("Vector hàng:\n", B)

# chuyển thành vector cột:
B_col = B.T
print("Vector cột:\n", B_col)
# câu lệnh điều kiện 
if A.shape[0] == B_col.shape[0]:
        C = np.hstack((A, B_col))
        print("Ma trận bổ sung (thêm vector cột): ")
        print(C)
else:
     print("Impossible")