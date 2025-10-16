def read_int(prompt=""):
    return int(input(prompt))

def main():
    m = read_int("Nhập số hàng m: ")
    n = read_int("Nhập số cột n: ")
    print(f"Nhập ma trận A ({m} hàng x {n} cột), nhập theo từng hàng (cách nhau bởi dấu cách):")
    A = []
    for i in range(m):
        row = input(f"Hàng {i+1}: ").strip().split()
        while len(row) != n:
            print(f" Nhập đúng {n} phần tử. Nhập lại hàng {i+1}:")
            row = input(f"Hàng {i+1}: ").strip().split()
        row = [float(x) for x in row]
        A.append(row)

    print("\nMa trận A:")
    for i in range(m):
        print(" ".join(f"{x:g}" for x in A[i]))

if __name__ == "__main__":
    main()