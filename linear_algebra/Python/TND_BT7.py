# Nhập ma trận
m = int(input("Nhập số hàng: "))
n = int(input("Nhập số cột: "))

A = []
print("Nhập các phần tử của ma trận:")
for i in range(m):
    while True:
        row = list(map(float, input(f"Hàng {i}: ").split()))
        if len(row) == n:
            A.append(row)
            break
        else:
            print(f"Cần nhập đúng {n} phần tử cho mỗi hàng!")

# Hàm in ma trận
def in_ma_tran(A):
    for row in A:
        print(" ".join(f"{x:8.2f}" for x in row))
    print()

# Menu các phép biến đổi
while True:
    print("1. Đổi chỗ hai dòng")
    print("2. Nhân một dòng với một số khác 0")
    print("3. Cộng dòng")
    print("0. Thoát")

    chon = input("Chọn phép biến đổi: ")

    if chon == "1":
        r1, r2 = map(int, input("Nhập hai dòng cần đổi (Hàng đầu tiên là số 0 không phải 1): ").split())
        if 0 <= r1 < m and 0 <= r2 < m:
            A[r1], A[r2] = A[r2], A[r1]
        else:
            print("Số dòng không hợp lệ!")
            continue

    elif chon == "2":
        r, k = map(float, input("Nhập dòng và hệ số k: ").split())
        r = int(r)
        if 0 <= r < m and k != 0:
            A[r] = [x * k for x in A[r]]
        else:
            print("Dòng hoặc hệ số không hợp lệ!")
            continue

    elif chon == "3":
        r1, r2, k = map(float, input("Nhập dòng nguồn, dòng đích và hệ số k: ").split())
        r1, r2 = int(r1), int(r2)
        if 0 <= r1 < m and 0 <= r2 < m:
            A[r2] = [A[r2][j] + k * A[r1][j] for j in range(n)]
        else:
            print("Số dòng không hợp lệ!")
            continue

    elif chon == "0":
        print("Kết thúc chương trình.")
        break
    else:
        print("Lựa chọn không hợp lệ!")
        continue

    print("\n Ma trận sau phép biến đổi:")
    in_ma_tran(A)
