# the problem 3 in ex3-4-5-6 folder
import math

def count_sequences(m, n):
    if m > n:
        return 0
    if n < 2 * m - 1:
        return 0
    return math.comb(n - m + 1, m)

if __name__ == "__main__":
    m = int(input("Nhap so luong m: "))
    n = int(input("Nhap do dai day n: "))
    count = count_sequences(m, n)
    print(f"So day thoa man: {count}")
