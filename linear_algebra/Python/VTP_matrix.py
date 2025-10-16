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

def nhan_ma_tran(A, B):
    m, p = len(A), len(A[0])
    p2, n = len(B), len(B[0])
    if p != p2:
        raise ValueError("Không nhân được: số cột của A phải bằng số hàng của B.")
    C = [[0]*n for _ in range(m)]
    for i in range(m):
        for j in range(n):
            for k in range(p):
                C[i][j] += A[i][k] * B[k][j]
    return C

def main():
    m = int(input("Nhập số hàng của A: "))
    p = int(input("Nhập số cột của A (cũng là số hàng của B): "))
    n = int(input("Nhập số cột của B: "))

    A = nhap_ma_tran(m, p, "A")
    B = nhap_ma_tran(p, n, "B")
    C = nhan_ma_tran(A, B)
    in_ma_tran(C, "C = A x B")

if __name__ == "__main__":
    main()