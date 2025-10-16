import numpy as np
n = int(input("Nhập số hàng: "))
m = int(input("Nhập số cột: "))
A = np.zeros((n,m))
for i in range(n):
    for j in range(m):
        A[i,j] = int(input(f"Nhập Phần tử A[{i}][{j}]: "))
print(A)
print()

a = int(input("Nhập số hàng: "))
b = int(input("Nhập số cột: "))
B = np.zeros((a,b))
for i in range(a):
    for j in range(b):
        B[i,j] = int(input(f"Nhập Phần tử A[{i}][{j}]: "))
print(B)
print()

C = A - B
print(f"{A} - {B} = {C}")
print()
D = A + B
print(f"{A} + {B} = {D}")