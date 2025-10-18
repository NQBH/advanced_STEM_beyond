m, n = map(int, input("Nhap so hang va so cot cua ma tran A: ").split())

A = []
print("Nhap cac phan tu cua ma tran A:")
for i in range(m):
    row = input(f"Dòng {i+1}: ").split()
    row_int = list(map(int, row))
    A.append(row_int)

print("Ma tran A la:")
for i in range(m):
    for j in range(n):
        print(A[i][j], end=" ")
    print()