X = int(input("Nhập số hàng: "))
Y = int(input("Nhập số cột: "))

A = [list(map(float, input(f"Hàng {i+1}: ").split())) for i in range(X)]

print("\nChọn phép biến đổi:")
print("1. Đổi chỗ hai hàng")
print("2. Nhân 1 hàng với số k khác 0")
print("3. Cộng một bội của hàng này vào hàng khác")

lua_chon = int(input("Nhập lựa chọn (1-3): "))

if lua_chon == 1:
    i, j = map(int, input("Nhập i, j: ").split())
    A[i-1], A[j-1] = A[j-1], A[i-1]
elif lua_chon == 2:
    i = int(input("Nhập hàng i: ")) - 1
    k = float(input("Nhập k: "))
    A[i] = [X * k for X in A[i]]
elif lua_chon == 3:
    i, j = map(int, input("Nhập i, j: ").split())
    k = float(input("Nhập k: "))
    A[i-1] = [A[i-1][c] + k * A[j-1][c] for c in range(Y)]
else:
    print("Hok hợp lệ. Nhập lại đi")

print("\nMa trận sau khi biến đổi:")
for row in A:
    print(row)
