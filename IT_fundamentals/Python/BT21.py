import math

def f(n):
    try:
        tu_so = n * n * math.sin(n)
        mau_so = math.sqrt(n * (n + 1) * abs(math.cos(n)))
        return tu_so / mau_so
    except:
        return 0

def a_n(n):
    if n == 0:
        return 1
    total = 0
    for k in range(n):
        j = n - k
        total += f(j) * a_n(k)
    return total

n = int(input("Nhập số n: "))
print(f"a_{n} = {a_n(n)}")

import math

def f(n):
    return (n**2 * math.sin(n)) / (math.sqrt(n * (n + 1)) * math.cos(n))

def a_n(n):
    if n == 0:
        return 1
    else:
        s = 0
        for k in range(n):
            s += f(n - k) * a_n(k)
        return s

# Nhập và in kết quả
n = int(input("Nhập n: "))
print(f"a[{n}] = {a_n(n)}")