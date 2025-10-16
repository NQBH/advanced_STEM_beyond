# Nhập ma trận A
m = int(input("Nhap so hang: "))
n = int(input("Nhap so cot: "))

A = []
print("Nhap cac phần tu ma tran:")
for i in range(m):
    row = list(map(float, input().split()))
    A.append(row)

B = []
print("Nhap cac phần tu ma tran:")
for i in range(m):
    row = list(map(float, input().split()))
    A.append(row)

C = [[A[i][j] + B[i][j] for j in range(len(A[0]))] for i in range(len(A))]

D = [[A[i][j] - B[i][j] for j in range(len(A[0]))] for i in range(len(A))]

print("A + B =", C)
print("A - B =", D)
