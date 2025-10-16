def nhap_ma_tran(m, n, ten="A"):
    print(f"Nhập ma trận {ten} ({m}x{n}):")
    M = []
    for i in range(m):
        row = list(map(float, input(f"Hàng {i+1}: ").split()))
        while len(row) != n:
            print(f"Phải nhập đúng {n} phần tử!")
            row = list(map(float, input(f"Hàng {i+1}: ").split()))
        M.append(row)
    return M

def in_ma_tran(M, ten="KQ"):
    print(f"\nMa trận {ten}:")
    for row in M:
        print(" ".join(f"{x:g}" for x in row))

def cong_tru_ma_tran(A, B, phep="cong"):
    m, n = len(A), len(A[0])
    C = []
    for i in range(m):
        row = []
        for j in range(n):
            if phep == "cong":
                row.append(A[i][j] + B[i][j])
            else:
                row.append(A[i][j] - B[i][j])
        C.append(row)
    return C

def main():
    m = int(input("Nhập số hàng m: "))
    n = int(input("Nhập số cột n: "))

    A = nhap_ma_tran(m, n, "A")
    B = nhap_ma_tran(m, n, "B")

    C_plus = cong_tru_ma_tran(A, B, "cong")
    C_minus = cong_tru_ma_tran(A, B, "tru")

    in_ma_tran(C_plus, "A + B")
    in_ma_tran(C_minus, "A - B")

if __name__ == "__main__":
    main()