def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

n = int(input("Nhập số tự nhiên n: "))
print(f"{n}! = {factorial(n)}")

def giaithua(n):
    if n == 0:
        return 1
    else:
        return n * giaithua(n - 1)

n = int(input())
if n < 0:
    pass
else:
    print(f"{n}! = {giaithua(n)}")

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

# Nhập số tự nhiên từ người dùng
n = int(input("Nhập một số tự nhiên: "))
result = factorial(n)
print(f"Giai thừa của {n} là: {result}")

def tinh_giai_thua(n):
    if n == 0:
        return 1
    else:
        return n * tinh_giai_thua(n - 1)

# Sử dụng:
n = int(input("Nhập số tự nhiên n: "))
print(f"{n}! = {tinh_giai_thua(n)}")

def giai_thua(n):
    if n == 0:
        return 1
    return n * giai_thua(n - 1)

n = int(input("Nhập số nguyên n: "))
print(f"{n}! = {giai_thua(n)}")

def tinh_giai_thua(n):
    if n == 0:
        return 1
    else:
        return n * tinh_giai_thua(n - 1)

# Sử dụng:
n = int(input("Nhập số tự nhiên n: "))
print(f"{n}! = {tinh_giai_thua(n)}")

#bai 1
def factorial(n):
    if n == 0:
        return 1  
    return n * factorial(n - 1)  
try:
    n = int(input("Nhập số tự nhiên n: "))
    if n < 0:
        print("Lỗi: n phải là số tự nhiên không âm.")
    else:
        result = factorial(n)
        print(f"{n}! = {result}")
except ValueError:
    print("Lỗi: nhập một số nguyên hợp lệ.")

def giai_thua_de_quy(n):
  if n==0:
    return 1
  else:
    return n*giai_thua_de_quy(n-1)
n=int(input())    
if n<0:
  print("khong co giai thua")
else:
  print(giai_thua_de_quy(n))

def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)
n = int(input("Nhập n: "))
print("Giai thừa của", n, "là:", factorial(n))

#bai 1
def tinh_giai_thua(n):
    if n == 0:
        return 1
    else:
        return n * tinh_giai_thua(n - 1)

n = int(input("Nhập số nguyên n: "))
ket_qua = tinh_giai_thua(n)
print(f"{n}! = {ket_qua}")

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

n = int(input("Nhập một số tự nhiên: "))
result = factorial(n)
print(f"Giai thừa của {n} là: {result}")

def giai_thua(n):
    if n == 0:
        return 1
    else:
        return n * giai_thua(n - 1)

n = int(input("Nhập số nguyên n: "))

if n < 0:
    print(" nhập số nguyên không âm.")
else:
    print(f"{n}! = {giai_thua(n)}")

def giai_thua(n):
    if n == 0:
        return 1
    return n * giai_thua(n - 1)

n = int(input("Nhập n: "))
print(f"{n}! = {giai_thua(n)}")

def giai_thua(n):
  if n == 0 or n == 1:
    return 1
  else:
    return n * giai_thua(n-1)
n = int(input("Nhập n: "))
print(f"{n}! = {giai_thua(n)}")