m = int(input("Nhap so hang: "))
n = int(input("Nhap so cot: "))

A = []
print("Nhap ma tran A:")
for i in range(m):
    row = []
    for j in range(n):
        row.append(float(input(f"A[{i}][{j}] = ")))
    A.append(row)

print("Ma tran A:")
for r in A:
    print(*r)

if m >= 2:
    A[0], A[1] = A[1], A[0]
    print("\nSau khi hoan doi hang:")
    for r in A:
        print(*r)
else:
    print("Loi")

for j in range(n):
    A[0][j] *= 2
print("\nSau khi nhan hang 1 voi 2:")
for r in A:
    print(*r)

if m >= 2:
    for j in range(n):
        A[1][j] += A[0][j]
    print("\nSau khi cong hang 1 vao hang 2:")
    for r in A:
        print(*r)
else:
    print("Loi")