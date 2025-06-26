def a_n(n):
    if n == 0:
        return 1
    total = 0
    for k in range(n):
        j = n - k
        total += j * j * a_n(k)
    return total

n = int(input("Nhập số n: "))
print(f"a_{n} = {a_n(n)}")

def a_n(n):
    if n == 0:
        return 1
    else:
        s = 0
        for k in range(n):
            s += (n - k)**2 * a_n(k)
        return s

# Nhập và in kết quả
n = int(input("Nhập n: "))
print(f"a[{n}] = {a_n(n)}")

def a(n):
    if n == 0:
        return 1
    total = 0
    for k in range(n):
        total += (n - k) ** 2 * a(k)
    return total

n = int(input("Nhập n: "))
print(f"a[{n}] =", a(n))

def a(n):
    if n == 0:
        return 1
    total = 0
    for i in range(n):
        total += (n - i) ** 2 * a(i)
    return total
try:
    n = int(input("Nhập n (n ∈ ℕ): "))
    if n < 0:
        print("Lỗi: n phải là số tự nhiên (n >= 0).")
    else:
        print(f"a[{n}] = {a(n)}")
except ValueError:
    print("Lỗi: Nhập một số nguyên hợp lệ.")