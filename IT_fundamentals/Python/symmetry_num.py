def la_so_doi_xung(n):
    if n < 0:
        return False  # Số âm không thể là số đối xứng
    str_n = str(n)
    return str_n == str_n[::-1]
n = int(input("Nhập một số nguyên: "))

if la_so_doi_xung(n):
    print(n, "là số đối xứng.")
else:
    print(n, "không phải là số đối xứng.")

def la_so_doi_xung(n):
    n_str = str(n)
    return n_str == n_str[::-1]
    
so = int(input("Nhập một số: "))
if la_so_doi_xung(so):
    print("Đây là số đối xứng")
else:
    print("Đây không phải là số đối xứng")

def la_so_doi_xung(n):
    chuoi = str(n)
    return chuoi == chuoi[::-1]

# Các ví dụ kiểm tra
cac_so = [1233321, 1231]

for so in cac_so:
    if la_so_doi_xung(so):
        print(f"Số {so} là số đối xứng.")
    else:
        print(f"Số {so} không phải là số đối xứng.")

def la_so_doi_xung(n):
    chuoi = str(n)
    return chuoi == chuoi[::-1]

so = int(input("Nhập một số: "))
if la_so_doi_xung(so):
    print(f"{so} là số đối xứng.")
else:
    print(f"{so} không phải là số đối xứng.")

n = input("Nhập số cần kiểm tra: ")

if n == n[::-1]:
    print("Đây là số đối xứng.")
else:
    print("Đây không phải là số đối xứng.")

#số đối xứng
def sodoixung():
  n = int(input())
  a = n
  x=0
  while n>0:
    x= x*10 + n%10
    n = n // 10
  if a == x:
    return True
  else:
    return False
  
print(sodoixung())

def doi_xung(n):
    s = str(n)
    s_dao = s[::-1]
    
    if s == s_dao:
        print(f"{n} là số đối xứng.")
        return True
    else:
        print(f"{n} không phải là số đối xứng.")
        return False
n = int(input())
doi_xung(n)

def la_so_doi_xung(n):
    return str(n) == str(n)[::-1]

so = int(input("Nhập số: "))
if la_so_doi_xung(so):
    print("Là số đối xứng.")
else:
    print("Không phải số đối xứng.")

def la_so_doi_xung(n):
    dao = 0
    tam = n
    while tam > 0:
        chu_so = tam % 10
        dao = dao * 10 + chu_so
        tam = tam // 10
    return dao == n
so = int(input("Nhập số: "))
if la_so_doi_xung(so):
    print("Là số đối xứng.")
else:
    print("Không phải số đối xứng.")

def la_so_doi_xung(n):
    n_str = str(n)               # Chuyển số thành chuỗi
    return n_str == n_str[::-1]  # So sánh chuỗi với chuỗi đảo ngược

# Ví dụ kiểm tra
print(la_so_doi_xung(1233321))  # True
print(la_so_doi_xung(1231))     # False

def kiem_tra_doi_xung(n):
    chuoi = str(n)             
    if chuoi == chuoi[::-1]:   
        return True
    else:
        return False
n = int(input("Nhập số nguyên: "))
if kiem_tra_doi_xung(n):
    print(n, "là số đối xứng.")
else:
    print(n, "không phải là số đối xứng.")