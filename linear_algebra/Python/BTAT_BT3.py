m, n = map(int, input("Nhap so hang va so cot: ").split())

A = []
print("Nhap ma tran A:")
for i in range(m):
    A.append(list(map(float, input().split())))

c = float(input("Nhap hang so c: "))

for i in range(m):
    for j in range(n):
        A[i][j] = A[i][j] * c

print(f"Ma tran sau khi nhan voi {c} la:")
for i in range(m):
    for j in range(n):
        print(A[i][j], end=" ")
    print()
