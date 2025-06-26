# Tính tổng S = 1!! - 2!! + 3!! - 4!! + ... + (-1)^(n+1) * n!!
n = int(input("Nhập n (số nguyên dương): "))
S = 0
for k in range(1, n + 1):
    giai_thua_kep = 1
    i = k
    while i > 0:
        giai_thua_kep *= i
        i -= 2
    if (k + 1) % 2 == 0:
        S += giai_thua_kep
    else:
        S -= giai_thua_kep

print("Tổng S =", S)

#bài23
def factorial_double(n):
    if n <= 0:
        return 1
    else:
        return n * factorial_double(n - 2) if n > 1 else 1

def total_sum(n):
    S = 0
    for i in range(1, n + 1):
        if i % 2 == 1:  # i lẻ
            S += factorial_double(i)
        else:  # i chẵn
            S -= factorial_double(i)
    return S

# Nhập n từ bàn phím
n = int(input("Nhập vào số nguyên dương n: "))
result = total_sum(n)
print(f"Tổng S cho n = {n} là: {result}")

# Bài 23:
def double_factorial(n):
    if n <= 0:
        return 1
    result = 1
    for i in range(n, 0, -2):
        result *= i
    return result

# Nhập n từ bàn phím
n = int(input("Nhập n (số nguyên dương): "))

S = 0
for i in range(1, n + 1):
    term = (-1) ** (i + 1) * double_factorial(i)
    S += term

print(f"Tổng S = {S}")

def double_factorial(k):
    result = 1
    while k > 0:
        result *= k
        k -= 2
    return result
n = int(input("Nhập số nguyên dương n: "))
S = 0
for i in range(1, n + 1):
    sign = (-1) ** (i + 1)   # Dấu: + - + - ...
    term = sign * double_factorial(i)
    S += term
print("Tổng S =", S)

def double_factorial(n):
    result = 1
    for i in range(n, 0, -2):
        result *= i
    return result

def calculate_S(n):
    S = 0
    for i in range(1, n+1):
        sign = (-1)**(i+1)
        S += sign * double_factorial(i)
    return S
n = int(input("Nhập n: "))
print("Giá trị tổng S là:", calculate_S(n))

def double_factorial(n):
    result = 1
    while n > 0:
        result *= n
        n -= 2
    return result

def tinh_tong_S(n):
    S = 0
    for i in range(1, n + 1):
        term = double_factorial(i)
        if i % 2 == 0:
            S -= term
        else:
            S += term
    return S

# Nhập và chạy
n = int(input("Nhập n: "))
print("Tổng S =", tinh_tong_S(n))

#bai 23 

def double_factorial(n):
    if n <= 0:
        return 1  
    else:
        return n * double_factorial(n - 2)  

def alternating_double_factorial_sum(n):
    S = 0  
    for i in range(1, n + 1):
        res = (-1) ** (i + 1)  
        S += res * double_factorial(i)
    return S
n = int(input("Nhập số nguyên dương n: "))
print(f"Tổng S = {alternating_double_factorial_sum(n)}")

#bai23
# Tính tổng S = 1!! - 2!! + 3!! - 4!! + ... + (-1)^(n+1) * n!!
n = int(input("Nhập n (số nguyên dương): "))
S = 0
for k in range(1, n + 1):
    giai_thua_kep = 1
    i = k
    while i > 0:
        giai_thua_kep *= i
        i -= 2
    if (k + 1) % 2 == 0:
        S += giai_thua_kep
    else:
        S -= giai_thua_kep

print("Tổng S =", S)

def double_factorial(n):
    result = 1
    for i in range(n, 0, -2):
        result *= i
    return result

def total_sum(n):
    return sum(
        double_factorial(i) if i % 2 else -double_factorial(i)
        for i in range(1, n + 1) )

if __name__ == "__main__":
    try:
        n = int(input("Nhập vào số nguyên dương n: "))
        if n <= 0:
            raise ValueError
        result = total_sum(n)
        print(f"Tổng S cho n = {n} là: {result}")
    except ValueError:
        print("Vui lòng nhập một số nguyên dương hợp lệ.")

def giai_thua_kep(n):
    kq = 1
    while n > 0:
        kq = kq * n
        n = n - 2
    return kq

def tinh_tong(n):
    tong = 0
    for i in range(1, n + 1):
        if (i + 1) % 2 == 0:  # dấu +
            tong = tong + giai_thua_kep(i)
        else:  # dấu -
            tong = tong - giai_thua_kep(i)
    return tong

n = int(input("Nhập số nguyên dương n: "))
print("Tổng S là:", tinh_tong(n))

#bai23
import math

def tinh_giai_thua_kep(n):
    ket_qua = 1
    for i in range(1, n+1):
        if i % 2 == n % 2:
            ket_qua *= i
    return ket_qua

def tinh_tong_S(n):
    tong_S = 0
    for i in range(1, n+1):
        giai_thua_kep = tinh_giai_thua_kep(i)
        tong_S += ((-1) ** (i + 1)) * giai_thua_kep
    return tong_S

n = int(input("Nhập n: "))
tong_S = tinh_tong_S(n)
print("Tổng S =", tong_S)

def giai_thua_kep(n):
  if n<0:
    return none
  if n==0 or n==1:
    return 1
  P=1
  for i in range(n,0,-2):
    P=P*i
  return P
n=int(input())
S=0
for i in range(n+1):
  A=(-1)**(i+1)*giai_thua_kep(2*i)
  S=S+A
print("s = ", S)

def giai_thua_kep(n):
  if n<0:
    return none
  if n==0 or n==1:
    return 1
  P=1
  for i in range(n,0,-2):
    P=P*i
  return P
n=int(input())
S=0
for i in range(1,n+1):
  A=(-1)**(i+1)*giai_thua_kep(i)
  S=S+A
print(S)

#bài 23
def giai_thua_kep(n):
    kq = 1
    while n > 0:
        kq *= n
        n -= 2
    return kq

n = int(input("Nhập n: "))
S = 0
for i in range(1, n + 1):
    S += ((-1) ** (i + 1)) * giai_thua_kep(i)
print("Tổng S =", S)