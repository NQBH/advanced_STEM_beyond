#Bai3
M=float(input())
Tong=0
n=1
x=1
for i in range(1,n+1):
  x*=i
phantu= (n*n)/x
while Tong + phantu < M:
  Tong+=phantu
  n+=1
  x=1
  for i in range(1,n+1):
    x*=i
  phantu= (n*n)/x
print(n-1)

#Bài 3
import math
M = float(input("Nhập M: "))
S = 0.0
n0 = 0

while True:
	n0 += 1
	term = (n0**2) / math.factorial(i)
	if S + term >= M:
		n0 -= 1
		break
	S += term

print("Giá trị n0 lớn nhất là", n0)
print("Tổng S tương ứng:", S)

# Ngoc Han
#bai 3
def tim_n0_voi_gioihan(M):
    S = 0
    i = 1
    giai_thua = 1
    while True:
        giai_thua = giai_thua * i
        S = S + i**2 / giai_thua
        if S >= M:
            return i - 1
        i = i + 1

M = float(input("Nhập giá trị M: "))
n0 = tim_n0_voi_gioihan(M)
print("Giá trị n₀ lớn nhất sao cho tổng S < M là:", n0)

def tim_n0_lon_nhat(M):
    n = 1
    S = 0
    giai_thua = 1

    while True:
        giai_thua *= n
        S += n**2 / giai_thua
        if S >= M:
            return n - 1 
        n += 1
M = float(input("Nhập số thực M: "))
n0 = tim_n0_lon_nhat(M)
print("Giá trị n₀ lớn nhất sao cho tổng S < M là:", n0)

#Bài 3
import math
M = float(input("Nhập M: "))
S = 0.0
n0 = 0

while True:
 n0 += 1
 term = (n0**2) / math.factorial(n0)
 if S + term >= M:
    n0 -= 1
    break
 S += term

print("Giá trị n0 lớn nhất là", n0)
print("Tổng S tương ứng:", S)

def tim_n0_lon_nhat(M):
    n = 1
    S = 0
    giai_thua = 1
    while True:
        giai_thua *= n             
        S += n**2 / giai_thua         
        if S >= M:
            return n - 1             
        n += 1
M = float(input("Nhập số thực M: "))
n0 = tim_n0_lon_nhat(M)
print("Giá trị n₀ lớn nhất sao cho tổng S < M là:", n0)

def tim_n0(M):
    S = 0
    n = 1
    while True:
        gt = 1
        j = 1
        while j <= n:
            gt *= j
            j += 1
        if S + n * n / gt >= M:
            break
        S += n * n / gt
        n += 1
    return n - 1

M = float(input("Nhập M: "))
print("n0 lớn nhất là:", tim_n0(M))

M = float(input("Nhập giá trị M: "))
n = 1
S = 0
giai_thua = 1
while True:
    giai_thua = giai_thua * n
    S = S + (n * n) / giai_thua
    if S >= M:
        break
    n = n + 1
print("Giá trị n₀ lớn nhất sao cho tổng S < M là:", n - 1)

#Bài 3
import math
M = float(input("Nhập M: "))
S = 0.0
n0 = 0

while True:
  n0 += 1
  term = (n0**2) / math.factorial(n0)
  if S + term >= M:
    n0 -= 1
    break
  S += term

print("Giá trị n0 lớn nhất là", n0)
print("Tổng S tương ứng:", S)

#bai3:
import math
M = float(input("Nhập số thực M: "))
n = 0
S = 0
while S < M:
    n += 1
    S += (n ** 2) / math.factorial(n)
print("n lớn nhất sao cho tổng S < M là:", n - 1)

#Bai 3 
import math
def tim_n0(M):
    S = n0 = 0
    while S + (n0+1)**2 / math.factorial(n0+1) < M:
        n0 += 1
        S += n0**2 / math.factorial(n0)
    return n0
M = float(input("Nhập giá trị M: "))
print("Giá trị n0 lớn nhất để tổng S < M là:", tim_n0(M))

import math

def find_max_n0(M):
    n = 1
    S = 0

    while True:
        S += (n**2) / math.factorial(n)
        if S >= M:
            break
        n += 1

    return n - 1  # Vì n hiện tại làm S >= M nên lấy n - 1

# Nhập M từ bàn phím
M = float(input("Nhập M: "))

# Gọi hàm và in kết quả
n0 = find_max_n0(M)
print("n₀ lớn nhất để S < M là:", n0)

def tim_n0(M):
    n = 1
    S = 0
    gt = 1  # giai thừa ban đầu là 1

    while True:
        gt = gt * n      # cập nhật giai thừa n!
        term = (n * n) / gt  # tính hạng tử n^2 / n!
        if S + term >= M:
            break
        S += term
        n += 1

    return n - 1  # trả về n0

# Nhập M từ bàn phím
M = float(input("Nhập giá trị M: "))
n0 = tim_n0(M)
print("n₀ lớn nhất sao cho tổng S < M là:", n0)

import math

def find_max_n0(M):
    S = 0
    n = 1
    while True:
        term = (n ** 2) / math.factorial(n)
        if S + term >= M:
            break
        S += term
        n += 1
    return n - 1  # Vì n hiện tại đã vượt quá M

# Nhập M từ bàn phím
M = float(input("Nhập giá trị M: "))

# Gọi hàm và in kết quả
n0 = find_max_n0(M)
print("Giá trị n0 lớn nhất sao cho tổng S < M là:", n0)

def tim_n_lon_nhat(M):
 n = 1
 S = 0
 giai_thua = 1
 while True:
    giai_thua = giai_thua * n
    S = S + (n * n) / giai_thua
    if S >= M:
      return n-1
    n = n + 1
M = float(input("Nhập giá trị M: "))
n0=tim_n_lon_nhat(M)
print(" n0 lớn nhất sao cho tổng S < M là:", n0)

#Bai 3
def tim_n0(M):
    n = 1
    S = 0.0
    giai_thua = 1
    while True:
        giai_thua *= n
        term = (n * n) / giai_thua
        if S + term >= M:
            break
        S += term
        n += 1
    return n - 1
M = float(input("Nhập số thực M: "))
n0 = tim_n0(M)
print("Giá trị n₀ lớn nhất sao cho tổng S < M là:", n0)

#BAI3
import math

M = float(input("Nhập số thực M: "))

n = 0   
S = 0.0 
while S < M:
    n += 1  
    # Cộng số hạng hiện tại (n^2 / n!) vào tổng S
    S += (n**2) / math.factorial(n)

print("n lớn nhất sao cho tổng S < M là:", n - 1)

def tim_n0(M):
    n = 1
    S = 0
    gt = 1  # giai thừa ban đầu là 1

    while True:
        gt = gt * n      # cập nhật giai thừa n!
        term = (n * n) / gt  # tính hạng tử n^2 / n!
        if S + term >= M:
            break
        S += term
        n += 1

    return n - 1  # trả về n0

# Nhập M từ bàn phím
M = float(input("Nhập giá trị M: "))
n0 = tim_n0(M)
print("n0 lớn nhất sao cho tổng S < M là:", n0)

#Bài 3
import math
M = float(input("Nhập giá trị M: "))
n = 0
S = 0
while S < M:
    n += 1
    S += (n ** 2) / math.factorial(n)
print("Gía trị n lớn nhất sao cho tổng S < M là  :", n - 1)