def thap_phan_sang_nhi_phan(n):
    if n == 0:
        return "0"
    nhi_phan = ""
    while n > 0:
        nhi_phan = str(n % 2) + nhi_phan
        n = n // 2
    return nhi_phan

n = int(input("Nhập số nguyên hệ thập phân: "))
print("Hệ nhị phân là:", thap_phan_sang_nhi_phan(n))

n = int(input("Nhập số thập phân: "))
kq = ""

if n == 0:
    kq = "0"
else:
    while n > 0:
        kq = str(n % 2) + kq
        n = n // 2

print("Hệ nhị phân là:", kq)

def dec_to_bin(n):
    result = ""
    while n > 0:
        result = str(n % 2) + result
        n = n // 2
    return result
n = int(input("Nhập số thập phân: "))
print(dec_to_bin(n))

def doi_sang_nhi_phan(n):
    if n == 0:
        return "0"
    ket_qua = ""
    while n > 0:
        ket_qua = str(n % 2) + ket_qua
        n = n // 2
    return ket_qua
so = int(input("Nhập số thập phân: "))
print("Dạng nhị phân:", doi_sang_nhi_phan(so))

def doi_sang_nhi_phan(n):
    if n == 0:
        return "0"
    ket_qua = ""
    while n > 0:
        ket_qua = str(n % 2) + ket_qua
        n = n // 2
    return ket_qua
so = int(input("Nhập số thập phân: "))
print("Dạng nhị phân:", doi_sang_nhi_phan(so))

def decimal_to_binary(n):
    if n == 0:
        return "0"
    binary = ""
    while n > 0:
        binary = str(n % 2) + binary
        n = n // 2
    return binary

def converter():
  n = int(input())
  if n==0:
    return "0"
  a = ""
  while n>0:
      a = str(n%2) + a
      n = n//2
  return a
print(converter())

def decimal_to_binary(n):
    if n == 0:
        return "0"
    binary = ""
    while n > 0:
        binary = str(n % 2) + binary
        n = n // 2
    return binary

number = int(input())
print(f"Số {number} trong hệ nhị phân là: {decimal_to_binary(number)}")

def doi_sang_nhi_phan(n):
    if n == 0:
        return "0"
    
    nhi_phan = []
    while n > 0:
        du = n % 2
        nhi_phan.insert(0, str(du))
        n = n // 2
    
    return ''.join(nhi_phan)

so = int(input("Nhập số thập phân: "))
nhi_phan = doi_sang_nhi_phan(so)
print("Dạng nhị phân:", nhi_phan)

# Đổi từ thập phân sang nhị phân
def dec_to_bin(n):
    result = ""
    while n > 0:
        result = str(n % 2) + result
        n = n // 2
    return result

# Define the variable number_decimal
number_decimal = int(input())

print(dec_to_bin(number_decimal))

def thap_phan_sang_nhi_phan(n):
    if n == 0:
        return "0"
    nhi_phan = ""
    while n > 0:
        nhi_phan = str(n % 2) + nhi_phan
        n = n // 2
    return nhi_phan

number_decimal = int(input())

print(thap_phan_sang_nhi_phan(number_decimal))

def chuyen_doi_dec_to_bin(so_thap_phan):
    """
    Chuyển đổi từ hệ 10 sang hệ 2
    """
    if so_thap_phan == 0:
        return "0"
    
    chuoi_nhi_phan = ""
    while so_thap_phan > 0:
        chuoi_nhi_phan = str(so_thap_phan % 2) + chuoi_nhi_phan
        so_thap_phan = so_thap_phan // 2
    
    return chuoi_nhi_phan

def thap_phan_sang_nhi_phan(n):
    if n == 0:
        return "0"
    ket_qua = ""
    while n > 0:
        ket_qua = str(n % 2) + ket_qua
        n = n // 2
    return ket_qua
n = int(input())
print(thap_phan_sang_nhi_phan(n))

def thap_phan_sang_nhi_phan(n):
    if n == 0:
        return "0"
    nhi_phan = ""
    while n > 0:
        nhi_phan = str(n % 2) + nhi_phan
        n = n // 2
    return nhi_phan

n = int(input("Nhập số nguyên hệ thập phân: "))
print("Hệ nhị phân là:", thap_phan_sang_nhi_phan(n))