#Bài 2
import math

n = int(input("Nhập số nguyên n: "))
s = 0.0
i = 1

while i <= n:
  s += (i**2) / math.factorial(i)
  i += 1

print("Tổng s =", s)

#bai 2
def tinh_tong_S(n):
    S = 0
    giai_thua = 1
    for i in range(1, n + 1):
        giai_thua = giai_thua * i     
        S += i**2 / giai_thua
    return S

n = int(input("Nhập số nguyên n: "))

tong = tinh_tong_S(n)
print("Tổng S =", tong)

#Bài 2
import math

n = int(input("Nhập số nguyên n: "))
S = 0.0

for i in range(1, n+1):
    S += (i**2) / math.factorial(i)

print("Tổng S =", S)

#Bai2
n= int(input())
a=0
for i in range(1,n+1):
  x=1
  for j in range(1,i+1):
    x*=j
  a+=i*i/x
print(a)

import math

def tinh_tong_S(n):
    """
    Tính tổng S = 1^2/1! + 2^2/2! + 3^2/3! + ... + n^2/n!
    """
    S = 0
    for i in range(1, n + 1):
        S += (i**2) / math.factorial(i)
    return S

n = int(input("Nhập số nguyên n: "))

ket_qua = tinh_tong_S(n)
print(f"Tổng S là: {ket_qua}")

def tinh_tong_S(n):
    S = 0
    giai_thua = 1
    for i in range(1, n + 1):
        giai_thua = giai_thua * i     
        S += i**2 / giai_thua  
    return S
n = int(input("Nhập số nguyên n: "))
tong = tinh_tong_S(n)
print("Tổng S =", round(tong, 2))

# bai 2
import math
n = int(input("Nhập số nguyên dương n: "))
S = 0
for i in range(1, n + 1):
    S += (i ** 2) / math.factorial(i)
print("Tổng S là:", S)

#bai2
import math
n = int(input("Nhập số nguyên n: "))
S = 0
for i in range(1, n + 1):
    S += (i ** 2) / math.factorial(i)
print("Tổng S là:", S)

import math

n = int(input("Nhập n: "))
S = 0

for i in range(1, n+1):
    S += (i**2) / math.factorial(i)

print("Tổng S là:", S)

import math

# Nhập số nguyên n từ bàn phím
n = int(input("Nhập số nguyên n: "))

# Khởi tạo tổng S ban đầu
S = 0

# Dùng vòng lặp for để tính tổng
for i in range(1, n + 1):
    S += (i ** 2) / math.factorial(i)

# In kết quả
print("Tổng S =", S)


# Nhập n từ bàn phím
n = int(input("Nhập số nguyên dương n: "))
# Khởi tạo tổng S
S = 0
# Vòng lặp từ 1 đến n
for i in range(1, n + 1):
    # Tính i^2
    i_binh_phuong = i * i
    # Tính i! (giai thừa)
    giai_thua = 1
    for j in range(1, i + 1):
        giai_thua *= j
    # Cộng vào tổng
    S += i_binh_phuong / giai_thua
# In kết quả
print("Tổng S =", S)

#bài 2
# Nhập số nguyên n từ bàn phím
n = int(input("Nhập số nguyên n: "))

# Khởi tạo tổng S
S = 0

# Tính tổng S
for k in range(1, n + 1):
    S += (k**2) / math.factorial(k)

# In kết quả
print("Tổng S =", S)

n = int(input("Nhập số nguyên n: "))
S = 0
for i in range(1, n + 1):
    S += (i ** 2) / math.factorial(i)
print("Tổng S là:", S)

#Bai2
import math
n = int(input("Nhập số nguyên dương n: "))
S = 0
for i in range(1, n + 1):
    S += (i ** 2) / math.factorial(i)
print("Tổng S là:", S)

import math

# Nhập n từ bàn phím
n = int(input("Nhập số nguyên dương n: "))

# Khởi tạo tổng
S = 0

# Vòng lặp for để tính tổng
for i in range(1, n + 1):
    term = (i ** 2) / math.factorial(i)
    S += term

# In kết quả
print("Tổng S là:", S)

import math
n = int(input("Nhập số nguyên n: "))
S = 0
for k in range(1, n + 1):
    S += (k**2) / math.factorial(k)
print(" S =", S)

import math

n = int(input("Nhập số nguyên n: "))

S = 0

for i in range(1, n + 1):
    S += i**2 / math.factorial(i)

print("Tổng S là:", S)

import math 

n = int(input("Nhap so nguyen n: "))
S = 0  
for i in range(1, n + 1):
    S += (i**2) / math.factorial(i)  
print("Tong S:", S)

import math
n = int(input("Nhập số nguyên dương n: "))
S = 0
for i in range(1, n + 1):
    S += (i**2) / math.factorial(i)
print("Tổng S =", S)

#Bai2:
import math
n = int(input("Nhập số nguyên n: "))
S = sum(i**2 / math.factorial(i) for i in range(1, n+1))
print("Tổng S là:", S)

#Bai 2
import math
n = int(input("Nhập số nguyên n: "))
S = 0 
for i in range(1, n+1):  
    tu_so = i**2        
    mau_so = math.factorial(i)  
    S += tu_so / mau_so  
print("Giá trị tổng S là:", S)