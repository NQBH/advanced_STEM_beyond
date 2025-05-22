n=int(input())
x=0
if n>9:
  for i in range(1,n):
    if n%i == 0:
       x+=i
       print(i)
  if x==n:
        print(f"{n} is perfect number")
  else:
        print(f"{n} is not perfect number") 
else:
  print("n must has 2 digits")

print("Bài toán 15")
n = int(input("Nhập số có 2 chữ số: "))
uoc = [i for i in range(1, n) if n % i == 0]
print(f"{n} là số hoàn hảo" if sum(uoc) == n else f"{n} không phải số hoàn hảo")
if sum(uoc) == n:
  print("các ước:",uoc)

#bai 15
n = int(input("Nhập một số nguyên dương: "))
tong_uoc = 0
print("Các ước tự nhiên của", n, "là:", end=" ")
for i in range(1, n):
    if n % i == 0:
        print(i, end=" ")
        tong_uoc += i
print("Tổng các ước tự nhiên =", tong_uoc)
if tong_uoc == n:
    print(n, "là số hoàn hảo.")
else:
    print(n, "không phải là số hoàn hảo.")

def la_so_hoan_hao(n):
    tong = 0
    for i in range(1, n):
        if n % i == 0:
            tong += i
    return tong == n
n = int(input("Nhập số nguyên dương cần kiểm tra: "))
if la_so_hoan_hao(n):
    print(n, "là số hoàn hảo.")
else:
    print(n, "không phải là số hoàn hảo.")

n = int(input("Nhập số tự nhiên: "))
sum_divisors = 0

for i in range(1, n):
    if n % i == 0:
        sum_divisors += i

if sum_divisors == n:
    print("YES")  # Là số hoàn hảo
else:
    print("NO")   # Không phải số hoàn hảo

n = int(input())
s = sum(i for i in range(1, n) if n % i == 0)
if s == n:
    print("Hoàn hảo")
    print(*[i for i in range(1, n+1) if n % i == 0])
else:
    print("Không hoàn hảo")

n = int(input("Nhập số nguyên dương cần kiểm tra: "))

tong_uoc = 0
for i in range(1, n):
    if n % i == 0:
        tong_uoc += i

if tong_uoc == n:
    print(f"{n} là số hoàn hảo.")
else:
    print(f"{n} không phải là số hoàn hảo.")

def la_so_hoan_hao(n):
    tong = 0
    for i in range(1, n):
        if n % i == 0:
            tong += i
    return tong == n

# Nhập số nguyên dương bất kỳ
n = int(input("Nhập số nguyên dương: "))

if la_so_hoan_hao(n):
    print(n, "là số hoàn hảo.")
else:
    print(n, "không phải là số hoàn hảo.")

def is_perfect_number(n):
    total = 0
    for i in range(1, n):
        if n % i == 0:
            total += i
    return total == n

# Nhập từ bàn phím
number = int(input("Nhập một số nguyên dương: "))

if is_perfect_number(number):
    print(f"{number} là số hoàn hảo")
else:
    print(f"{number} không phải là số hoàn hảo")

n = int(input("Nhập số tự nhiên có 2 chữ số: "))
tong_uoc = sum(i for i in range(1, n) if n % i == 0)

if tong_uoc == n:
    print(f"{n} là số hoàn hảo.")
    print(f"Danh sách ước của {n}: {[i for i in range(1, n+1) if n % i == 0]}")
else:
    print(f"{n} không phải là số hoàn hảo.")