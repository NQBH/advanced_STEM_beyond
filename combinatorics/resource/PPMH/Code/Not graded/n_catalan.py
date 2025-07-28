# the ex2 in ex2-3 folder
import math

def catalan_number(n):
    return math.comb(2 * n, n) // (n + 1)

if __name__ == "__main__":
    n = int(input("Nhap so cap hoac n: "))
    c = catalan_number(n)
    print(f"So cach dat {n} cap ngoac dung la: {c}")
