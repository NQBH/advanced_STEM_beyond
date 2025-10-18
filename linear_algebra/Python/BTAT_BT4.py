m, n, p = map(int, input("Nhap so hang, cot cua A va cot cua B: ").split())

A = []
print("Nhap ma tran A:")
for i in range(m):
    A.append(list(map(int, input().split())))

B = []
print("Nhap ma tran B:")
for i in range(n):
    B.append(list(map(int, input().split())))

C = [[0 for _ in range(p)] for _ in range(m)]

for i in range(m):
    for j in range(p):
        for k in range(n):
            C[i][j] += A[i][k] * B[k][j]

print("Tich hai ma tran la:")
for i in range(m):
    for j in range(p):
        print(C[i][j], end=" ")
    print()
