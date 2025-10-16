
def nhap_ma_tran():
    m, n = map(int, input("Nhập số dòng và cột: ").split())
    A = []
    for i in range(m):
        row = list(map(float, input(f"Nhập dòng {i+1}: ").split()))
        A.append(row)
    return A, m, n

def xuat_ma_tran(A):
    for row in A:
        print("\t".join(f"{x:.2f}" for x in row))

A, m, n = nhap_ma_tran()

print("\nMa trận ban đầu:")
xuat_ma_tran(A)

print("\nChọn phép biến đổi:")
print("1. Hoán đổi hai dòng")
print("2. Nhân một dòng với một hằng số")
print("3. Cộng bội của dòng này vào dòng khác")
choice = int(input("Nhập lựa chọn: "))

if choice == 1:
    i, j = map(int, input("Nhập hai dòng cần hoán đổi (1-{}): ".format(m)).split())
    A[i-1], A[j-1] = A[j-1], A[i-1]
elif choice == 2:
    i, k = input("Nhập dòng và hằng số k: ").split()
    i, k = int(i), float(k)
    A[i-1] = [x * k for x in A[i-1]]
elif choice == 3:
    i, j, k = input("Nhập dòng i, dòng j và hệ số k (R_i = R_i + k*R_j): ").split()
    i, j, k = int(i), int(j), float(k)
    A[i-1] = [A[i-1][c] + k * A[j-1][c] for c in range(n)]
else:
    print("Lựa chọn không hợp lệ!")

print("\nMa trận sau biến đổi:")
xuat_ma_tran(A)