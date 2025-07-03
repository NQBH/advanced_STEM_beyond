def la_so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True
def tao_day_fibonacci(n):
    if n == 0:
        return []
    elif n == 1:
        return [0]
    fib = [0, 1]
    for i in range(2, n):
        fib.append(fib[i - 1] + fib[i - 2])
    return fib
def in_so_nguyen_to_trong_fibonacci(n):
    day_fibo = tao_day_fibonacci(n)
    print(f"Dãy Fibonacci độ dài {n} là: {day_fibo}")
    print("Các số nguyên tố trong dãy Fibonacci là:")
    for so in day_fibo:
        if la_so_nguyen_to(so):
            print(so, end=" ")
    print()
n = int(input("Nhập độ dài dãy Fibonacci: "))
in_so_nguyen_to_trong_fibonacci(n)

# Hàm kiểm tra số nguyên tố
def la_so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# Hàm sinh dãy Fibonacci dài n phần tử
def sinh_day_fibonacci(n):
    fib = []
    a, b = 0, 1
    for _ in range(n):
        fib.append(a)
        a, b = b, a + b
    return fib

# Hàm in ra các số nguyên tố trong dãy Fibonacci
def in_so_nguyen_to_fibonacci(n):
    fib = sinh_day_fibonacci(n)
    print(f"Các số nguyên tố trong {n} số Fibonacci đầu tiên là:")
    for so in fib:
        if la_so_nguyen_to(so):
            print(so, end=' ')
    print()

# Chạy chương trình
n = int(input("Nhập độ dài dãy Fibonacci: "))
in_so_nguyen_to_fibonacci(n)
 
def la_so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def in_so_nguyen_to_fibo(n):
    a, b = 0, 1
    print("Các số nguyên tố trong dãy Fibonacci:")
    for _ in range(n):
        if la_so_nguyen_to(a):
            print(a, end=' ')
        a, b = b, a + b

# Nhập từ bàn phím
n = int(input("Nhập độ dài dãy Fibonacci: "))
in_so_nguyen_to_fibo(n)

def la_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def fibonacci_nguyen_to(n):
    a, b = 0, 1
    for _ in range(n):
        if la_nguyen_to(a):
            print(a, end=" ")
        a, b = b, a + b

n = int(input("Nhập số lượng số Fibonacci: "))
print("Các số nguyên tố trong dãy Fibonacci:")
fibonacci_nguyen_to(n)

n = int(input("Nhập độ dài dãy Fibonacci: "))

print("NHN:")
f0 = 0
f1 = 1

print("Các số nguyên tố trong dãy Fibonacci là:")

for i in range(n):
    if f0 > 1:
        dem = 0
        for j in range(2, f0):
            if f0 % j == 0:
                dem += 1
        if dem == 0:
            print(f0, end=" ")

    f2 = f0 + f1
    f0 = f1
    f1 = f2

def la_so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def in_so_nguyen_to_fibonacci(n):
    f0, f1 = 0, 1
    for _ in range(n):
        if la_so_nguyen_to(f0):
            print(f0, end=' ')
        f0, f1 = f1, f0 + f1

n = int(input("Nhập độ dài dãy Fibonacci: "))
print("Các số nguyên tố trong dãy Fibonacci là:")
in_so_nguyen_to_fibonacci(n)