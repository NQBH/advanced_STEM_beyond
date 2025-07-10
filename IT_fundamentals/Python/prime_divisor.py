def uoc_nguyen_to(n):
    i = 2
    uoc = set()
    while i * i <= n:
        if n % i == 0:
            uoc.add(i)
            while n % i == 0:
                n //= i
        i += 1
    if n > 1:
        uoc.add(n)
    return uoc

# Nhập số từ bàn phím
n = int(input("Nhập số nguyên dương n: "))
tap_uoc = uoc_nguyen_to(n)
print(f"Các ước nguyên tố của {n} là: {sorted(tap_uoc)}")
print(f"Tổng số ước nguyên tố: {len(tap_uoc)}")

def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

def count_prime_factors(n):
    count = 0
    for i in range(2, n + 1):
        if n % i == 0 and is_prime(i):
            count += 1
    return count

n = int(input("Nhập số nguyên dương n: "))
print("Số ước nguyên tố của", n, "là:", count_prime_factors(n))

def dem_uoc_nguyen_to(n):
    dem = 0
    i = 2
    while i * i <= n:
        if n % i == 0:
            dem += 1
            while n % i == 0:
                n //= i
        i += 1
    if n > 1:
        dem += 1
    return dem

n = int(input("Nhập số nguyên dương n: "))
print("Số ước nguyên tố khác nhau là:", dem_uoc_nguyen_to(n))

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True
def count_prime_factors(n):
    prime_factors = set()
    i = 2
    while i * i <= n:
        if n % i == 0:
            if is_prime(i):
                prime_factors.add(i)
            n //= i
        else:
            i += 1
    if n > 1 and is_prime(n):
        prime_factors.add(n)
    return len(prime_factors)
n = int(input("Nhập số nguyên dương n: "))
print(f"Số ước nguyên tố khác nhau của {n} là: {count_prime_factors(n)}")

def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

def count_prime_factors(n):
    count = 0
    for i in range(2, n + 1):
        if n % i == 0 and is_prime(i):
            count += 1
    return count

n = int(input("Nhập số nguyên dương n: "))
print("Số ước nguyên tố của", n, "là:", count_prime_factors(n))

def la_so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

def dem_uoc_nguyen_to(n):
    dem = 0
    i = 2
    while i <= n:
        if n % i == 0 and la_so_nguyen_to(i):
            dem += 1
            while n % i == 0:
                n //= i
        i += 1
    return dem

# Nhập từ bàn phím và in kết quả
n = int(input("Nhập số nguyên dương n: "))
print("Số ước nguyên tố khác nhau của", n, "là:", dem_uoc_nguyen_to(n))

#bài 1
n = int(input("Nhập số nguyên dương: "))
i = 2
dem = 0
bieu_thuc = f"{n} = "
dau = ""

while i * i <= n:
    mu = 0
    while n % i == 0:
        n //= i
        mu += 1
    if mu > 0:
        dem += 1
        bieu_thuc += f"{dau}{i}^{mu}" if mu > 1 else f"{dau}{i}"
        dau = " * "
    i += 1

if n > 1:
    dem += 1
    bieu_thuc += f"{dau}{n}"

print(bieu_thuc)
print("Số ước nguyên tố khác nhau là:", dem)

def dem_uoc_nguyen_to(n):
    dem = 0
    for i in range(2, n + 1):
        # Kiểm tra i có phải là ước của n và là số nguyên tố không
        if n % i == 0:
            # Kiểm tra i có phải là số nguyên tố
            la_nguyen_to = True
            for j in range(2, int(i**0.5) + 1):
                if i % j == 0:
                    la_nguyen_to = False
                    break
            if la_nguyen_to:
                dem += 1
    return dem

# Nhập số từ bàn phím
n = int(input("Nhập số nguyên dương n: "))
print("Số ước nguyên tố của", n, "là:", dem_uoc_nguyen_to(n))