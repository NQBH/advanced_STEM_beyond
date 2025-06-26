def S_a(n):
    if n == 0:
        return 0
    return 1/(2*n) + S_a(n-1)

n = int(input("Nhập n: "))
print("S(a) =", S_a(n))

def S_b(n):
    if n == 0:
        return 0
    return n**n + S_b(n-1)

n = int(input("Nhập n: "))
print("S(b) =", S_b(n))


import math

def S_c(n):
    if n == 1:
        return math.sqrt(3)
    return math.sqrt(3*n + S_c(n-1))

n = int(input("Nhập n: "))
print("S(c) =", S_c(n))

import math

def S_d(n):
    if n == 1:
        return 1  
    
    return n**(1/n) + S_d(n-1)

n = int(input("Nhập n: "))
print("S(d) =", S_d(n))


import math

def S_e(n, depth=2):
    if n == 1:
        return math.sqrt(1)  
    if n == depth:
        return (n + S_e(n-1, depth+1))**(1/depth)
    return math.sqrt(n + S_e(n-1, depth+1))

n = int(input("Nhập n: "))
print("S(e) =", S_e(n))

import math

def S_f(n):
    if n == 1:
        return math.sqrt(1)  
    
    U = math.sqrt(n-1 + S_f(n-1))
    return U**(1/n)  

n = int(input("Nhập n: "))
print("S(f) =", S_f(n))


import math

def factorial(k):
    if k == 0 or k == 1:
        return 1
    return k * factorial(k-1)

def S_g(n):
    if n == 1:
        return math.sqrt(1)  
    U = math.sqrt(factorial(n) + S_g(n-1))
    return U**(1/n)  

n = int(input("Nhập n: "))
print("S(g) =", S_g(n))

import math

def factorial(k):
    if k == 0 or k == 1:
        return 1
    return k * factorial(k-1)

def S_h(n, x):
    if n == 0:
        return 0
    term = x**n / factorial(n)
    return term + S_h(n-1, x)

x = float(input("Nhập x: "))
n = int(input("Nhập n: "))
s = S_h(n, x)
e_x = math.exp(x)
print("S(h) =", s)
print("e^x - S(n) =", e_x - s)

22 
a)
def tong_a(n):
    if n == 1:
        return 1 / 2
    return 1 / (2 * n) + tong_a(n - 1)

n = int(input("Nhập n: "))
print(f"S = {tong_a(n)}")
b)
def tong_b(n):
    if n == 1:
        return 1
    return n**n + tong_b(n - 1)

n = int(input("Nhập n: "))
print(f"S = {tong_b(n)}")
c)
import math

def tong_c(k):
    if k == 1:
        return math.sqrt(3)
    return math.sqrt(3 * k + tong_c(k - 1))

n = int(input("Nhập n: "))
print(f"S = {tong_c(n)}")
D)
def tong_d(n):
    if n == 2:
        return 2 ** (1/2)
    return n ** (1/n) + tong_d(n - 1)

n = int(input("Nhập n: "))
print(f"S = {tong_d(n)}")
e)
def tong_e(k):
    if k == 1:
        return 1
    return (k - 1 + tong_e(k - 1)) ** (1 / k)

n = int(input("Nhập n: "))
print(f"S = {(n + tong_e(n)) ** (1 / (n + 1))}")
f)
import math

def tong_f(k):
    if k == 1:
        return math.sqrt(1)
    return math.sqrt(k + tong_f(k - 1))

n = int(input("Nhập n: "))
print(f"S = {tong_f(n)}")
g)
import math

def giaithua(n):
    if n == 0 or n == 1:
        return 1
    return n * giaithua(n - 1)

def tong_g(k):
    if k == 1:
        return math.sqrt(giaithua(1))
    return (giaithua(k - 1) + tong_g(k - 1)) ** (1 / k)

n = int(input("Nhập n: "))
print(f"S = {(giaithua(n) + tong_g(n)) ** (1 / (n + 1))}")
H)
import math

def giaithua(n):
    if n == 0 or n == 1:
        return 1
    return n * giaithua(n - 1)

def tong_h(n, x):
    if n == 1:
        return x
    return (x ** n) / giaithua(n) + tong_h(n - 1, x)

x = float(input("Nhập x: "))
n = int(input("Nhập n: "))
s = tong_h(n, x)
print(f"S(n) = {s}")
print(f"e^x - S(n) = {math.exp(x) - s}")