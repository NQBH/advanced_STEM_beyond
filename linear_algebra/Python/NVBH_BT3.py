m = int(input("Nhap so hang: "))
n= int(input("Nhap so cot: "))

A = []
print("Nhap cac phần tu ma tran:")
for i in range(m):
    row = list(map(float, input().split()))
    A.append(row)

c = float(input("Nhap hang so c: "))

B = [[c * A[i][j] for j in range(len(A[0]))] for i in range(len(A))]

print("c * A =", B)