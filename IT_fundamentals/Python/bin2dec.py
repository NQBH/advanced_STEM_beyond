def nhi_phan_sang_thap_phan(binary_str):
    thap_phan = 0
    for i, digit in enumerate(reversed(binary_str)):
        if digit == '1':
            thap_phan += 2 ** i
    return thap_phan

# Nhập từ bàn phím
binary_input = input("Nhập số hệ nhị phân: ")
print("Hệ thập phân là:", nhi_phan_sang_thap_phan(binary_input))

nhi_phan = input("Nhập số nhị phân: ")
thap_phan = 0
mu = 0

for so in nhi_phan[::-1]:
    thap_phan += int(so) * (2 ** mu)
    mu += 1

print("Hệ thập phân là:", thap_phan)

def binary_to_decimal(binary_str):
    decimal = 0
    for i in range(len(binary_str)):
        bit = int(binary_str[-(i + 1)])
        decimal += bit * (2 ** i)
    return decimal

# Hàm chuyển từ nhị phân sang thập phân
def binary_to_decimal(binary_str):
    decimal = 0
    length = len(binary_str)
    for i in range(length):
        bit = int(binary_str[length - i - 1])
        decimal += bit * (2 ** i)
    return decimal
binary_input = input("Nhập số nhị phân (ví dụ: 1011): ")
try:
    if set(binary_input) <= {'0', '1'}:
        result = binary_to_decimal(binary_input)
        print(f"Số thập phân tương ứng là: {result}")
    else:
        print("Lỗi: chỉ được nhập các chữ số 0 và 1.")
except Exception as e:
    print("Đã xảy ra lỗi:", e)

def binary_to_decimal(binary_str):
    decimal = 0
    power = 0
    for digit in reversed(binary_str):
        if digit == '1':
            decimal += 2 ** power
        power += 1
    return decimal

binary_input = input()
print(f"Số nhị phân {binary_input} tương ứng thập phân là: {binary_to_decimal(binary_input)}")

#nhị phân sang thập phân
def Coverter2():
    n = input()
    a=0
    for i in n:
        a = a*2 + int(i)
    return a
print(Coverter2())

# Đổi từ nhị phân sang thập phân
def bin_to_dec(b):
    result = 0
    power = 0
    for digit in b[::-1]:
        result += int(digit) * (2 ** power)
        power += 1
    return result

# Define the variable number_binary
number_binary = input()

print(bin_to_dec(number_binary))

def nhi_phan_sang_thap_phan(nhi_phan_str):
    thap_phan = 0
    for i in range(len(nhi_phan_str)):
        bit = int(nhi_phan_str[-(i + 1)])
        thap_phan += bit * (2 ** i)
    return thap_phan

def nhi_phan_sang_thap_phan(nhi_phan):
    ket_qua = 0
    luy_thua = 1
    for chu_so in reversed(nhi_phan):
        ket_qua += int(chu_so) * luy_thua
        luy_thua *= 2
    return ket_qua
n = input()
print(nhi_phan_sang_thap_phan(n))

def doi_bin_thanh_dec(chuoi_binary):
    """
    Chuyển đổi từ hệ 2 sang hệ 10
    """
    tong = 0
    chieu_dai = len(chuoi_binary)
    
    for vi_tri in range(chieu_dai):
        if chuoi_binary[vi_tri] == '1':
            luy_thua = chieu_dai - 1 - vi_tri
            tong += 2 ** luy_thua

n = input()
print(doi_bin_thanh_dec(n))