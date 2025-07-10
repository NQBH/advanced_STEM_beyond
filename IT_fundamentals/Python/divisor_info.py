def divisor_info(n):
    num_divisor = 0
    sum_divisor = 0
    product_divisor = 1

    for i in range(1, n + 1):
        if n % i == 0:
            num_divisor += 1
            sum_divisor += i
            product_divisor *= i

    return num_divisor, sum_divisor, product_divisor

# Nhập từ bàn phím
n = int(input("Nhập số nguyên dương n: "))
num_div, sum_div, prod_div = divisor_info(n)

print(f"Số lượng ước số của {n} là: {num_div}")
print(f"Tổng các ước số của {n} là: {sum_div}")
print(f"Tích các ước số của {n} là: {prod_div}")

def divisor_info(n):
    count = 0
    total = 0
    product = 1
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            j = n // i
            if i == j:
                count += 1
                total += i
                product *= i
            else:
                count += 2
                total += i + j
                product *= i * j
    return count, total, product
n = int(input("Nhập số nguyên dương n: "))
num_divisor, sum_divisor, product_divisor = divisor_info(n)
print(f"Số lượng ước của {n}: {num_divisor}")
print(f"Tổng các ước của {n}: {sum_divisor}")
print(f"Tích các ước của {n}: {product_divisor}")

n = int(input("Nhập số nguyên dương n: "))

so_uoc = 0
tong_uoc = 0
tich_uoc = 1

print("Các ước của", n, "là:")

for i in range(1, n + 1):
    if n % i == 0:
        print(i)
        so_uoc += 1
        tong_uoc += i
        tich_uoc *= i

print("Số lượng ước:", so_uoc)
print("Tổng các ước:", tong_uoc)
print("Tích các ước:", tich_uoc)

def divisor_info(n):
    count = 0
    total = 0
    product = 1
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            j = n // i
            if i == j:
                count += 1
                total += i
                product *= i
            else:
                count += 2
                total += i + j
                product *= i * j
    return count, total, product

n = int(input("Nhập số nguyên dương n: "))
num_divisor, sum_divisor, product_divisor = divisor_info(n)

print(f"num_divisor = {num_divisor}")
print(f"sum_divisor = {sum_divisor}")
print(f"product_divisor = {product_divisor}")

def thong_tin_uoc(n):
    so_uoc = 0
    tong_uoc = 0
    tich_uoc = 1

    for i in range(1, n + 1):
        if n % i == 0:
            so_uoc += 1
            tong_uoc += i
            tich_uoc *= i

    return so_uoc, tong_uoc, tich_uoc

n = int(input("Nhập số nguyên dương n: "))
so, tong, tich = thong_tin_uoc(n)

print("Số lượng ước:", so)
print("Tổng các ước:", tong)
print("Tích các ước:", tich)

n = int(input("Nhập số nguyên dương n: "))

so_uoc = 0
tong_uoc = 0
tich_uoc = 1

print("Các ước của", n, "là:")

for i in range(1, n + 1):
    if n % i == 0:
        print(i)
        so_uoc += 1
        tong_uoc += i
        tich_uoc *= i

print("Số lượng ước:", so_uoc)
print("Tổng các ước:", tong_uoc)
print("Tích các ước:", tich_uoc)