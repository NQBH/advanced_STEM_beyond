m = int(input("Nhap so hang cua ma tran A: "))
n = int(input("Nhap so cot cua ma tran A: "))

A = []
print("Nhap cac phan tu ma tran A (m dong, moi dong n so cach nhau boi dau cach):")
for i in range(m):
    row = list(map(float, input().split()))
    if len(row) != n:
        print("So cot khong dung, vui long nhap lai dong nay.")
        row = list(map(float, input().split()))
    A.append(row)

k = int(input("Nhap so cot cua ma tran B: "))
B = []
print("Nhap cac phan tu ma tran B (n dong, moi dong k so cach nhau boi dau cach):")
for i in range(n):
    row = list(map(float, input().split()))
    if len(row) != k:
        print("So cot khong dung, vui long nhap lai dong nay.")
        row = list(map(float, input().split()))
    B.append(row)

C = [[0]*k for _ in range(m)]

for i in range(m):
    for j in range(k):
        for t in range(n):
            C[i][j] += A[i][t] * B[t][j]

print("A * B =")
for row in C:
    print(row)