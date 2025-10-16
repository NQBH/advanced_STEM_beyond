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

def nhan_vo_huong(A, c):
    return [[c * x for x in row] for row in A]

def main():
    m = int(input("Nhập số hàng m: "))
    n = int(input("Nhập số cột n: "))
    c = float(input("Nhập số thực c: "))

    A = nhap_ma_tran(m, n, "A")
    C = nhan_vo_huong(A, c)

    in_ma_tran(C, f"c*A (c={c})")

if __name__ == "__main__":
    main()