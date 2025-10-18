m, n = map(int, input("Nhap so hang va so cot cua ma tran A: ").split())
A = []
print("Nhap ma tran A:")
for i in range(m):
    A.append(list(map(float, input().split())))

print("1. Doi cho hai hang")
print("2. Nhan 1 hang voi alpha")
print("3. Cong alpha lan hang i vao hang j")
choice = int(input("Chon phep bien doi: "))

if choice == 1:
    r1, r2 = map(int, input("Nhap hai hang muon doi: ").split())
    A[r1], A[r2] = A[r2], A[r1]
elif choice == 2:
    r = int(input("Nhap hang r: "))
    alpha = float(input("Nhap alpha: "))
    A[r] = [x * alpha for x in A[r]]
elif choice == 3:
    i, j, alpha = input("Nhap i, j, alpha: ").split()
    i, j, alpha = int(i), int(j), float(alpha)
    A[j] = [A[j][k] + alpha * A[i][k] for k in range(n)]
else:
    print("Lua chon khong hop le!")

print("Ma tran sau bien doi:")
for row in A:
    print(*row)