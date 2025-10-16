m, n = map(int, input("Nhap so hang m va so cot n cua ma tran A: ").split())

A = []
print("Nhap cac phan tu cua A (moi hang nhap tren 1 dong):")
for i in range(m):
    hang = list(map(float, input().split()))
    A.append(hang)

print("\nMa tran A ban dau:")
for hang in A:
    print(*hang)

print("\nChon phep bien doi so cap tren dong:")
print("1. Doi cho 2 hang")
print("2. Nhan mot hang voi mot so khac 0")
print("3. Cong mot boi cua hang nay vao hang khac")

choice = int(input("Nhap lua chon (1, 2 hoac 3): "))

if choice == 1:
    r1 = int(input("Nhap so hang thu nhat muon doi (tinh tu 1): "))
    r2 = int(input("Nhap so hang thu hai muon doi (tinh tu 1): "))

    temp = A[r1 - 1]
    A[r1 - 1] = A[r2 - 1]
    A[r2 - 1] = temp

elif choice == 2:

    r = int(input("Nhap so hang muon nhan (tinh tu 1): "))
    k = float(input("Nhap he so k (k khac 0): "))

    for j in range(n):
        A[r - 1][j] = A[r - 1][j] * k

elif choice == 3:

    r1 = int(input("Nhap hang bi cong (r1 - tinh tu 1): "))
    r2 = int(input("Nhap hang duoc nhan roi cong vao (r2 - tinh tu 1): "))
    k = float(input("Nhap he so k: "))

    for j in range(n):
        A[r1 - 1][j] = A[r1 - 1][j] + k * A[r2 - 1][j]

else:
    print("Lua chon khong hop le! ")

print("\nMa tran sau khi thuc hien phep bien doi: ")
for hang in A:
    print(*hang)