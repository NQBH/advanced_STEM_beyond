def print_matrix(A):
    for hang in A:
        for phan_tu in hang:
            print(round(phan_tu, 2), end=" ")
        print()

m = int(input("Nhap so hang m: "))
n = int(input("Nhap so cot n: "))

A = []
for i in range(m):
    dong = [float(input(f"A[{i}][{j}] = ")) for j in range(n)]
    A.append(dong)

while True:
    print("\n1. Hoan doi 2 dong")
    print("2. Nhan 1 dong voi mot so khac 0")
    print("3. Cong 1 dong voi dong khac da nhan voi mot so")
    print("0. Thoat")
    lua_chon = int(input("Nhap lua chon: "))

    if lua_chon == 0:
        break
    elif lua_chon == 1:
        r1, r2 = int(input("Dong thu nhat: ")), int(input("Dong thu hai: "))
        if 0 <= r1 < m and 0 <= r2 < m:
            A[r1], A[r2] = A[r2], A[r1]
    elif lua_chon == 2:
        r = int(input("Dong can nhan: "))
        k = float(input("He so k (khac 0): "))
        if 0 <= r < m and k != 0:
            for j in range(n):
                A[r][j] *= k
    elif lua_chon == 3:
        r1, r2 = int(input("Dong bi thay doi: ")), int(input("Dong nguon: "))
        k = float(input("He so k: "))
        if 0 <= r1 < m and 0 <= r2 < m:
            for j in range(n):
                A[r1][j] += k * A[r2][j]
    else:
        print("Lua chon khong hop le.")

    print("Ma tran sau bien doi:")
    print_matrix(A)