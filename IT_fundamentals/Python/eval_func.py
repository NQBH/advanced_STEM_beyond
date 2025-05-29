#Bai1
x,y,z = map(float,input().split())
def evaluate_function(x,y,z):
  a = (x**3 * y**2 * z**0.5) / (x**0.5 * y**(1/3))
  print(a)
evaluate_function(x,y,z)

#Bai1                                                                                                                            x = float(input("Nhập giá trị của x: "))
x,y,z = map(float,input().split())
# Tính các thành phần của biểu thức
tu_so = x**3 * y**2 * z**(1/2)
mau_so = x**(1/2) * y**(1/3)

# Kiểm tra mẫu số khác 0 trước khi chia
if mau_so != 0:
  A = tu_so / mau_so
  print("Giá trị của biểu thức A là:", A)
else:
  print("Mẫu số bằng 0. Không thể tính giá trị A.")

#Bài 1
def evaluate_function(x, y, z):
  return (x**3 * y**2 * z**0.5) / (x**0.5 * (y**(1/3)))

x,y,z = map(float,input().split())
print("Kết quả:", evaluate_function(x, y, z))

#bai 1
import math
def evaluate_function(x, y, z):
    numerator = x**3 * y**2 * math.sqrt(z)
    denominator = math.sqrt(x) * y**(1/3)
    A = numerator / denominator
    return A
x,y,z = map(float,input().split())
A = evaluate_function(x, y, z)
print("Giá trị của biểu thức A là:", A)

import math
def evaluate_function(x, y, z):
    numerator = (x ** 3) * (y ** 2) * (math.sqrt(z))
    denominator = math.sqrt(x) * (y ** (1/3))
    A = numerator / denominator
    return A

x,y,z = map(float, input().split())
result = evaluate_function(x, y, z)
print("Giá trị của biểu thức A là:", result)

import math

def evaluate_function(x, y, z):
    A = (x**3 * y**2 * math.sqrt(z)) / (math.sqrt(x) * y**(1/3))
    return A

# Nhập x, y, z từ bàn phím
x,y,z = map(float, input().split())

# Gọi hàm và in kết quả
ket_qua = evaluate_function(x, y, z)
print("Giá trị của biểu thức A là:", ket_qua)

import math

def evaluate_function(x, y, z):
    return (x**3 * y**2 * math.sqrt(z)) / (math.sqrt(x) * y**(1/3))

x,y,z = map(float, input().split())

print("A =", evaluate_function(x, y, z))

#bai1
def evaluate_function(x, y, z):
    a = (x**3 * y**2 * z**0.5) / (x**0.5 * y**(1/3))
    return a
x, y, z = map(float,input("Nhập x, y, z: ").split())
A = evaluate_function(x, y, z)
print("Giá trị biểu thức A là:", A)

import math

def evaluate_function(x, y, z):
  """
  Tính giá trị biểu thức A = x^3 * y^2 * sqrt(z) / (sqrt(x) * cbrt(y))
  """
  tu_so = (x**3) * (y**2) * math.sqrt(z)
 
  mau_so = math.sqrt(x) * (y**(1/3))

  A = tu_so / mau_so
  return A

x_val, y_val, z_val = map(float,input("Nhập x, y, z: ").split())

ket_qua_A = evaluate_function(x_val, y_val, z_val)
print(f"Giá trị của biểu thức A là: {ket_qua_A}")

#bai1
import math

def evaluate_function(x, y, z):
    A = (x**3 * y**2 * z**(1/2)) / (math.sqrt(x) * y**(1/3))
    return A

# Nhập giá trị cho x, y từ bàn phím
x, y, z = map(float,input("Nhập x, y, z: ").split())

# Gọi hàm để tính A
result = evaluate_function(x, y, z)
print(f"Giá trị của A là: {result}")

#bai 1
def evaluate_function(x, y, z):
    A = (x**3 * y**2 * z**0.5) / (x**0.5 * y**(1/3))
    return A

x, y, z = map(float,input("Nhập x, y, z: ").split())

print("Giá trị A =", round(evaluate_function(x, y, z), 2))

import math

def evaluate_function(x, y, z):
    # Tính toán theo biểu thức đã cho
    numerator = (x**3) * (y**2) * math.sqrt(z)
    denominator = math.sqrt(x) * (y**(1/3))
    A = numerator / denominator
    return A

# Nhập giá trị x, y, z từ bàn phím
x, y, z = map(float,input("Nhập x, y, z: ").split())


# Gọi hàm và in kết quả
ket_qua = evaluate_function(x, y, z)
print("Giá trị của biểu thức A là:", ket_qua)

import math

def evaluate_function(x, y, z):
    return (x**3 * y**2 * math.sqrt(z)) / (math.sqrt(x) * y**(1/3))

x, y, z = map(float,input("Nhập x, y, z: ").split())

print("Gia tri cuar bieu thuc A la:", evaluate_function(x, y, z))

import math

# Hàm tính giá trị biểu thức A
def evaluate_function(x, y, z):
    A = (x**3 * y**2 * math.sqrt(z)) / (math.sqrt(x) * y**(1/3))
    return A

x, y, z = map(float,input("Nhập x, y, z: ").split())

# Gọi hàm và in kết quả
A = evaluate_function(x, y, z)
print("Giá trị A =", A)

import math
def evaluate_function(x, y, z):
    numerator = x**3 * y**2 * math.sqrt(z)
    denominator = math.sqrt(x) * y**(1/3)
    A = numerator / denominator
    return A
x, y, z = map(float,input("Nhập x, y, z: ").split())
A = evaluate_function(x, y, z)
print(f"Giá trị của biểu thức A là: {A:.2f}")


def evaluate_function(x, y, z):
    A = (x**3 * y**2 * math.sqrt(z)) / (math.sqrt(x) * y**(1/3))
    return A
x, y, z = map(float,input("Nhập x, y, z: ").split())

print("Giá trị biểu thức A là:", evaluate_function(x, y, z))

def evaluate_function(x,y,z):
  A =(x**3 * y**2 * z**0.5) / (x**0.5 * y**(1/3))

  return A
x, y, z = map(float,input("Nhập x, y, z: ").split())
ket_qua = evaluate_function(x, y, z)
print("A=", ket_qua)

#bai1:
import math
def evaluate_function(x, y, z):
    return (x**3 * y**2 * z**0.5) / (x**0.5 * y**(1/3))
x, y, z = map(float,input("Nhập x, y, z: ").split())
A = evaluate_function(x, y, z)
print("Giá trị biểu thức A là:", A)

def evaluate_function(x, y, z):
  return (x**23 * y**2 * z**0.5) / (x**0.5 * (y**(1/3)))

x, y, z = map(float,input("Nhập x, y, z: ").split())

print("Kết quả:", evaluate_function(x, y, z))

import math

def evaluate_function(x, y, z):
    # Tính tử số và mẫu số riêng cho rõ ràng
    numerator = x**3 * y**2 * math.sqrt(z)
    denominator = math.sqrt(x) * y**(1/3)
    A = numerator / denominator
    return A

# Nhập x, y từ bàn phím
x, y, z = map(float,input("Nhập x, y, z: ").split())

# Gọi hàm và in kết quả
A = evaluate_function(x, y, z)
print("Giá trị biểu thức A là:", A)

#Xuan Khanh gui lai bai 1
import math
def evaluate_function(x, y, z):
    A = (x**3 * y**2 * math.sqrt(z)) / (math.sqrt(x) * y**(1/3))
    return A
# Nhập giá trị từ bàn phím
x, y, z = map(float,input("Nhập x, y, z: ").split())

print("Giá trị biểu thức A là:", A)