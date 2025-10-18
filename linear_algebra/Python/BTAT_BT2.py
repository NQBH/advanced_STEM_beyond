m, n = map(int, input("Nhap so hang va so cot cua ma tran: ").split())

A = []
print("Nhap ma tran A:")
for i in range(m):
    A.append(list(map(int, input().split())))

B = []
print("Nhap ma tran B:")
for i in range(m):
    B.append(list(map(int, input().split())))

op = input("Nhap phep toan (+ hoac -): ")

C = [[0 for _ in range(n)] for _ in range(m)]
for i in range(m):
    for j in range(n):
        if op == '+':
            C[i][j] = A[i][j] + B[i][j]
        else:
            C[i][j] = A[i][j] - B[i][j]

print("Ket qua la:")
for i in range(m):
    for j in range(n):
        print(C[i][j], end=" ")
    print()
