def la_so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def liet_ke_so_nguyen_to_n_chu_so(n):
    bat_dau = 10**(n - 1)
    ket_thuc = 10**n - 1
    danh_sach = []

    for i in range(bat_dau, ket_thuc + 1):
        if la_so_nguyen_to(i):
            danh_sach.append(i)

    return danh_sach

n = int(input("Nhập số chữ số (n): "))
cac_so_nt = liet_ke_so_nguyen_to_n_chu_so(n)
print(f"Có {len(cac_so_nt)} số nguyên tố có {n} chữ số:")
print(cac_so_nt)

def la_nguyen_to(x):
    if x < 2:
        return False
    for i in range(2, int(x**0.5)+1):
        if x % i == 0:
            return False
    return True

def liet_ke_nguyen_to_n_chu_so(n):
    dem = 0
    bat_dau = 10**(n-1)
    ket_thuc = 10**n
    for i in range(bat_dau, ket_thuc):
        if la_nguyen_to(i):
            print(i, end=" ")
            dem += 1
    print(f"\nCó {dem} số nguyên tố có {n} chữ số.")

n = int(input("Nhập số chữ số: "))
liet_ke_nguyen_to_n_chu_so(n)

# Hàm kiểm tra số nguyên tố
def la_so_nguyen_to(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# Hàm đếm và liệt kê số nguyên tố có n chữ số
def liet_ke_so_nguyen_to_n_chu_so(n):
    bat_dau = 10**(n - 1)
    ket_thuc = 10**n - 1
    dem = 0
    print(f"Các số nguyên tố có {n} chữ số là:")
    for i in range(bat_dau, ket_thuc + 1):
        if la_so_nguyen_to(i):
            print(i, end=' ')
            dem += 1
    print(f"\nTổng cộng có {dem} số nguyên tố có {n} chữ số.")

# Nhập từ bàn phím và chạy
n = int(input("Nhập số chữ số n: "))
liet_ke_so_nguyen_to_n_chu_so(n)