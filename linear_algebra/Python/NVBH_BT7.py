# Nhập ma trận A
m, n = map(int, input("Nhap so hang m va so cot n cua ma tran A: ").split())
print(f"Nhap ma tran A ({m}x{n}):")
A = [list(map(float, input().split())) for _ in range(m)]

print("\n=== CAC PHEP BIEN DOI SO CAP ===")
print("1. Hoan vi hai hang")
print("2. Nhan mot hang voi hang so k")
print("3. Cong mot hang voi boi cua hang khac")

choice = int(input("Chon phep bien doi (1-3): "))

if choice == 1:
    i, j = map(int, input("Nhap hai chi so hang i va j (0-based): ").split())
    A[i], A[j] = A[j], A[i]
elif choice == 2:
    i, k = input("Nhap chi so hang i va hang so k: ").split()
    i, k = int(i), float(k)
    A[i] = [x * k for x in A[i]]
elif choice == 3:
    i, j, k = input("Nhap i, j va he so k (Ri = Ri + k*Rj): ").split()
    i, j, k = int(i), int(j), float(k)
    A[i] = [A[i][c] + k * A[j][c] for c in range(n)]
else:
    print("Lua chon khong hop le.")

print("\nMa tran sau khi bien doi:")
for row in A:
    print(*row)
