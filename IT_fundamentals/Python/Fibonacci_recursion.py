def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

n = int(input("Nhập số nguyên n ≥ 0: "))

if n < 0:
    print("Vui lòng nhập số không âm!")
else:
    print(f"F[{n}] = {fibonacci(n)}")

def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fib(n - 1) + fib(n - 2)
n = int(input("Nhập n: "))
for i in range(n + 1):
    print(f"F[{i}] =", fib(i))

#bai 2
def fibonacci(n):
    if n == 0:
        return 0            
    elif n == 1:
        return 1            
    else:
        # F[n] = F[n-1] + F[n-2]
        return fibonacci(n - 1) + fibonacci(n - 2)

n = int(input("Nhập số nguyên n: "))
print(f"F[{n}] = {fibonacci(n)}")

#bài2
def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

def fibo(i, n):
    if i > n:
        return
    print(f"F[{i}] = {fibonacci(i)}")
    fibo(i + 1, n)

n = int(input())
if n < 0:
    pass
else:
    fibo(0, n)
    print(f"F[{n}] = {fibonacci(n)}")

#bai 2
def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

n = int(input("Nhập số nguyên n: "))
print(f"Dãy Fibonacci từ F[0] đến F[{n}]:")
for i in range(n + 1):
    print(f"F[{i}] = {fibonacci(i)}")

#bai 2
def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)
def print_fibonacci(n):
    if n == 0:
        print(fibonacci(0), end=' ')
    else:
        print_fibonacci(n - 1)
        print(fibonacci(n), end=' ')
try:
    n = int(input("Nhập số nguyên n (n ≥ 0): "))
    if n < 0:
        print("Lỗi: n phải ≥ 0")
    else:
        print("Dãy Fibonacci từ F[0] đến F[{}]:".format(n))
        print_fibonacci(n)
except ValueError:
    print("Lỗi: Nhập số nguyên hợp lệ.")

# Hàm đệ quy tính số Fibonacci thứ n
def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)

# Nhập n từ bàn phím
n = int(input("Nhập n: "))

# In ra dãy số Fibonacci từ F[0] đến F[n]
print(f"Dãy Fibonacci từ F[0] đến F[{n}]:")
for i in range(n + 1):
    print(f"F[{i}] = {fibonacci(i)}")

def fibonacci(n):
  if n==0:
    return 0
  elif n==1:
    return 1
  else:
    return fibonacci(n-1)+fibonacci(n-2)
n=int(input())
if n<0:
  print("Error")
else:
  for i in range(n + 1):
    print(f"F[{i}] = {fibonacci(i)}")

def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

def in_fibonacci(i, n):
    if i > n:
        return
    print(f"F[{i}] = {fibonacci(i)}")
    in_fibonacci(i + 1, n)

n = int(input("Nhập n: "))
print("Dãy Fibonacci từ F[0] đến F[n]:")
in_fibonacci(0, n)