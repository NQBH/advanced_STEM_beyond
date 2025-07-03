def phan_tich_thua_so_nguyen_to(n):
    if n <= 1:
        return "Số phải lớn hơn 1."

    i = 2
    phan_tich = {}
    while i * i <= n:
        dem = 0
        while n % i == 0:
            n //= i
            dem += 1
        if dem > 0:
            phan_tich[i] = dem
        i += 1
    if n > 1:
        phan_tich[n] = 1

    ket_qua = " * ".join(f"{p}^{e}" if e > 1 else str(p) for p, e in phan_tich.items())
    return ket_qua
n = int(input("Nhập số nguyên dương (>1): "))

ket_qua = phan_tich_thua_so_nguyen_to(n)
print(f"{n} =", ket_qua)

def phan_tich_thua_so_nt(n):
    i = 2
    ket_qua = {}
    while i * i <= n:
        dem = 0
        while n % i == 0:
            dem += 1
            n //= i
        if dem > 0:
            ket_qua[i] = dem
        i += 1
    if n > 1:
        ket_qua[n] = 1
    return ket_qua

n = int(input("Nhập số nguyên dương: "))
thua_so = phan_tich_thua_so_nt(n)
chuoi = f"{n} = " + '*'.join(f"{p}^{e}" for p, e in thua_so.items())
print(chuoi)

n = int(input("Nhập số nguyên dương: "))
i = 2
print(n, "=", end=" ")
dau = 0  

while n > 1:
    dem = 0
    while n % i == 0:
        n = n // i
        dem += 1
    if dem > 0:
        if dau > 0:
            print("*", end="")
        print(f"{i}^{dem}", end="")
        dau += 1
    i += 1

def phan_tich_thua_so_nguyen_to(n):
    ket_qua = ""
    i = 2  # Bắt đầu từ số nguyên tố nhỏ nhất
    while n > 1:
        dem = 0
        while n % i == 0:
            n //= i
            dem += 1
        if dem > 0:
            ket_qua += f"{i}^{dem} × "
        i += 1
    # Bỏ dấu "× " cuối cùng và trả về kết quả
    return ket_qua[:-3]

so = int(input("Nhập số nguyên dương: "))
print(f"{so} = {phan_tich_thua_so_nguyen_to(so)}")

def phan_tich_thua_so_nguyen_to(n):
    if n <= 1:
        print("Số phải lớn hơn 1.")
        return

    i = 2
    result = ""
    while i * i <= n:
        count = 0
        while n % i == 0:
            n //= i
            count += 1
        if count > 0:
            result += f"{i}^{count}*" if count > 1 else f"{i}*"
        i += 1

    if n > 1:
        result += f"{n}"  # số còn lại là số nguyên tố

    elif result.endswith("*"):
        result = result[:-1]  # bỏ dấu * ở cuối

    print("Phân tích:", result)
n = int(input())
phan_tich_thua_so_nguyen_to(n)

def phan_tich_thua_so_nguyen_to(n):
    i = 2
    result = []
    while n > 1:
        count = 0
        while n % i == 0:
            n = n // i
            count += 1
        if count > 0:
            if count == 1:
                result.append(str(i))
            else:
                result.append(f"{i}^{count}")
        i += 1
    return " * ".join(result)
n = int(input())
print(n, "=", phan_tich_thua_so_nguyen_to(n))

def phan_tich_thua_so_nguyen_to(n):
    i = 2
    ket_qua = {}
    while i * i <= n:
        dem = 0
        while n % i == 0:
            dem += 1
            n //= i
        if dem > 0:
            ket_qua[i] = dem
        i += 1
    if n > 1:
        ket_qua[n] = 1
    return ket_qua
n = int(input())
print(phan_tich_thua_so_nguyen_to(n))

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        while n % i == 0:
            factors.append(i)
            n //= i
        i += 1
    if n > 1:
        factors.append(n)
    return factors
n = int(input())
print(prime_factors(n))  # Output: [2, 3, 3, 5]

def phan_tich_thua_so_nguyen_to(n):
    i = 2
    factors = {}
    while i * i <= n:
        while n % i == 0:
            factors[i] = factors.get(i, 0) + 1
            n //= i
        i += 1
    if n > 1:
        factors[n] = 1

    # Tạo chuỗi kết quả theo dạng toán học
    ket_qua = '*'.join([f"{p}^{e}" if e > 1 else str(p) for p, e in factors.items()])
    return ket_qua

n = int(input())
print(phan_tich_thua_so_nguyen_to(n))

def phan_tich_thua_so_nguyen_to(n):
    i = 2  
    ket_qua = ""
    
    while i * i <= n:
        dem = 0
        while n % i == 0:
            n = n // i
            dem += 1
        if dem > 0:
            if ket_qua != "":
                ket_qua += "*"
            ket_qua += f"{i}^{dem}"
        i += 1
    
    if n > 1:
        if ket_qua != "":
            ket_qua += "*"
        ket_qua += f"{n}^1"
    
    return ket_qua

n = int(input("Nhập số nguyên dương: "))
print(f"{n} =", phan_tich_thua_so_nguyen_to(n))