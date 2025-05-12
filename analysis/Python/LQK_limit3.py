import math

def main():
    try:
        epsilon = float(input("Nhap epsilon (ε > 0): "))
        if epsilon <= 0:
            print("ε phai lon hon 0.")
            return
    except ValueError:
        print("nhap mot so thuc hop le.")
        return

    n = 0
    while (n + 1) / (3 ** n) >= epsilon:
        n += 1
        if n > 1000:
            print("Khong tim thay trong 1000 buoc.")
            return

    print(f"(d) Gia tri nho nhat cua n sao cho (n+1)/3^n < ε la: {n}")

if __name__ == "__main__":
    main()