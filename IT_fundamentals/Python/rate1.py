print("Nhập số tiền gửi, lãi suất  (% năm), số năm:")
tien_goc, lai_suat, so_nam = map(float, input().split())
so_nam = int(so_nam)
print("kết quả")
for nam in range(1, so_nam  + 1):
  tien_nhan_duoc = tien_goc * (1 + lai_suat/100)**nam
  print(f"Năm {nam}: {tien_nhan_duoc:,.0f} đồng")
print("Nhập số tiền mục tiêu:")
tien_muc_tieu = float(input())

nam_can = 0
while tien_goc * (1 + lai_suat/100)**nam_can < tien_muc_tieu:
  nam_can += 1

print(f"cần {nam_can} năm để đạt {tien_muc_tieu:,.0f} đồng")
def compute_amount(m0, r, n):
    return m0 * ((1 + r / 100) ** n)
m0, r, n = map(float, input("Nhập m0, r, n (cách nhau bởi dấu cách): ").split())
n = int(n)

# (a) Tính T(m0, r, n)
T_final = compute_amount(m0, r, n)
print(f"{T_final:.3f}")

# (b) Xuất dãy {T(m0, r, i)} từ i = 1 đến n
for i in range(1, n + 1):
    T_year = compute_amount(m0, r, i)
    print(f"{T_year:.3f}", end=' ')
print()

# (c) Tìm số năm nhỏ nhất để vượt qua một số tiền m
m = float(input("Nhập số tiền kỳ vọng m: "))
year = 1
while compute_amount(m0, r, year) <= m:
    year += 1
print(f"Sau {year} năm thì số tiền vượt {m}")

#bai8
print("Tính tiền gửi")
tienbandau= float(input("Nhập số tiền gửi: "))
r= float(input("Nhập lãi suất/năm: "))
tienmuctieu = float(input("Nhập số tiền muốn đạt được: "))
nam=0
T=tienbandau
while T<=tienmuctieu:
  nam += 1
  T = tienbandau * (1+r)**nam
print(f"Số năm cần gửi là: {nam}")
for i in range(1,nam+1):
  Ti = tienbandau * (1+r)**i
  print(f"Tiền gửi năm {i}: {Ti}")

m0, r, n = map(float, input("Nhập m0, r, n: ").split())
n = int(n)
Tien_nhan = m0 * (1 + r / 100) ** n
print(round(Tien_nhan, 3)) 
for i in range(1, n + 1):
    T = m0 * (1 + r / 100) ** i
    print(round(T, 3), end=' ')
m = float(input("Nhập số tiền kỳ vọng m: "))
year = 0
current = m0
while current <= m:
    year = year + 1
    current = m0 * (1 + r / 100) ** year
print("Số năm vượt qua số tiền kỳ vọng:", year)

# Nhập m0, r, n
m0, r, n = map(float, input("Nhập m0, r, n (cách nhau bởi dấu cách): ").split())
n = int(n)

# Phần (a) - Tính tiền sau n năm
Tn = m0 * (1 + r / 100) ** n
print("Số tiền sau", n, "năm là:", round(Tn, 3))

# Phần (b) - In dãy tiền qua các năm
print("Dãy số tiền sau mỗi năm:")
for i in range(1, n + 1):
    Ti = m0 * (1 + r / 100) ** i
    print(f"Năm {i}: {round(Ti, 3)}")

# Phần (c) - Nhập m kỳ vọng, tìm năm đầu tiên vượt qua m
m = float(input("Nhập số tiền kỳ vọng m: "))

nam = 0
T = m0
while T < m:
    nam += 1
    T = m0 * (1 + r / 100) ** nam

print(f"Sau {nam} năm thì số tiền vượt qua {m}.")
print(f"Số tiền nhận được lúc đó là: {round(T, 3)}")

# Nhap m0, r, n
m0, r, n = map(float, input("Nhap m0, r, n : ").split())
n = int(n)

# Phan a - tinh tien sau n nam
Tn = m0 * (1 + r / 100) ** n
print("so tien sau", n, "nam la:", round(Tn, 3))

# Phan b - in day tien qua cac nam
print("Day so tien moi nam:")
for i in range(1, n + 1):
    Ti = m0 * (1 + r / 100) ** i
    print(f"Nam {i}: {round(Ti, 3)}")

# Phan c - Nhap m ky vong, tim nam dau tien vuot qua m
m = float(input("Nhap so tien mong muon m: "))

nam = 0
T = m0
while T < m:
    nam += 1
    T = m0 * (1 + r / 100) ** nam

print(f"Sau {nam} nam thi moi tien vuot qua {m}.")
print(f"So tien nhan la : {round(T, 3)}")

nhap= input().split()
m0= float(nhap[0])
r= float(nhap[1])
n= float(nhap[2])
kq= m0*(1+r/100)**n
print(round(kq,2))
for i in range(1,int(n)+1):
    print(round(m0*(1+r/100)**i,2))
m=float(input("nhap so tien ky vong:"))
nam = 0
T = m0
while T < m:
    nam += 1
    T = m0 * (1 + r / 100) ** nam
    print(round(T,2))
print(nam)

# Hàm tính lãi kép
def compound_interest(m0, r, n):
    return m0 * ((1 + r / 100) ** n)

# Hàm chính mô phỏng bài toán
def solve_in_colab(m0, r, n):
    print(f"Dữ liệu đầu vào: m0 = {m0}, r = {r}, n = {n}")
    
    # Tính tổng tiền sau n năm
    total = compound_interest(m0, r, n)
    
    # Tạo dãy tiền qua từng năm
    sequence = [compound_interest(m0, r, i) for i in range(1, n + 1)]
    
    # In ra kết quả
    print(f"\nTổng tiền sau {n} năm: {total:.3f}")
    print("Tiền từng năm:")
    for i, val in enumerate(sequence, 1):
        print(f"Năm {i}: {val:.3f}")

#  Gọi hàm với dữ liệu mẫu (giống đề bài)
solve_in_colab(125000000, 4.9, 3)

# Nhap m0, r, n
m0, r, n = map(float, input("Nhap m0, r, n : ").split())
n = int(n)

# a - tinh tien sau n nam
Tn = m0 * (1 + r / 100) ** n
print("so tien sau", n, "nam la:", round(Tn, 3))

# b - in day tien qua cac nam
print("Day so tien moi nam:")
for i in range(1, n + 1):
    Ti = m0 * (1 + r / 100) ** i
    print(f"Nam {i}: {round(Ti, 3)}")

# c - Nhap m ky vong, tim nam dau tien vuot qua m
m = float(input("Nhap so tien mong muon m: "))

nam = 0
T = m0
while T < m:
    nam += 1
    T = m0 * (1 + r / 100) ** nam

print(f"Sau {nam} nam thi moi tien vuot qua {m}.")
print(f"So tien nhan la : {round(T, 3)}")

def tinh_tien_lai_kep(mo, r, n):
    return mo * (1 + r / 100) ** n

def tinh_danh_sach_tien(mo, r, n):
    return [round(mo * (1 + r / 100) ** i, 3) for i in range(1, n + 1)]

def tim_nam_vuot_m(mo, r, m):
    nam = 0
    so_tien = mo
    while so_tien <= m:
        so_tien *= (1 + r / 100)
        nam += 1
    return nam

# (a) Nhập đầu vào
mo, r, n = map(float, input("Nhập mo, r, n cách nhau bởi dấu cách: ").split())
n = int(n)

# (a) Tính T(mo, r, n)
tong_tien = tinh_tien_lai_kep(mo, r, n)
print(f"{tong_tien:.3f}")

# (b) In danh sách T(mo, r, i) với i từ 1 đến n
danh_sach = tinh_danh_sach_tien(mo, r, n)
print(" ".join(f"{val:.3f}" for val in danh_sach))

# (c) Nhập số tiền kỳ vọng m và tìm số năm cần để vượt qua m
m = float(input("Nhập số tiền kỳ vọng m: "))
so_nam = tim_nam_vuot_m(mo, r, m)
print(f"Sau {so_nam} năm, số tiền vượt quá {m}")

m0, r, n = map(float, input().split())
n = int(n)

# Tính và in T(m0, r, n)
T = lambda m0, r, n: m0 * (1 + r / 100) ** n
print(round(T(m0, r, n), 3))

# In dãy T(m0, r, 1) đến T(m0, r, n)
for i in range(1, n + 1):
    print(round(T(m0, r, i), 3), end=' ')
print()

# Nhập m, tìm năm đầu tiên vượt m
m = float(input())
i = 1
while T(m0, r, i) <= m:
    i += 1
print(f"Sau {i} năm thì vượt {m}")

def calculate_M(m0, r, n):
    # Công thức tính M
    return m0 * (1 + r / 100) ** n

def main():
    # Nhập dữ liệu từ người dùng
    m0, r, n = map(float, input().split())
    n = int(n)

    # Xuất kết quả cho từng năm
    print(f"{'Năm':<10}{'M(m0, r, n, i)':<20}")
    for i in range(1, n + 1):
        M = calculate_M(m0, r, i)
        print(f"{i:<10}{M:<20.2f}")

if __name__ == "__main__":
    main()
m = input()

m0, r, n = map(float, input("Nhap m0, r, n : ").split())
n = int(n)

Tn = m0 * (1 + r / 100) ** n
print("so tien sau", n, "nam la:", round(Tn, 3))

print("Day so tien moi nam:")
for i in range(1, n + 1):
    Ti = m0 * (1 + r / 100) ** i
    print(f"Nam {i}: {round(Ti, 3)}")

m = float(input("Nhap so tien mong muon m: "))

nam = 0
T = m0
while T < m:
    nam += 1
    T = m0 * (1 + r / 100) ** nam

print(f"Sau {nam} nam thi moi tien vuot qua {m}.")
print(f"So tien nhan la : {round(T, 3)}")

def calculate_total_money(m0, r,n):
    return m0 * (1 + r / 100)**n
m0, r, n = map(float, input().split())
total_after_n_years = calculate_total_money(m0, r, n)
print(total_after_n_years)
money_each_year = []
for i in range(1, int(n)+1):
  money = calculate_total_money(m0, r, i)
  money_each_year.append(money)
print("".join(map(str, money_each_year)))

m = input()

m0, r, n = map(float, input().split())
n = int(n)

# Tính và in T(m0, r, n)
T = lambda m0, r, n: m0 * (1 + r / 100) ** n
print(round(T(m0, r, n), 3))

# In dãy T(m0, r, 1) đến T(m0, r, n)
for i in range(1, n + 1):
    print(round(T(m0, r, i), 3), end=' ')
print()

# Nhập m, tìm năm đầu tiên vượt m
m = float(input())
i = 1
while T(m0, r, i) <= m:
    i += 1
print(f"Sau {i} năm thì vượt {m}")

def T(m0, r, n):
    return m0 * (1 + r / 100) ** n

def sequence_T(m0, r, n):
    return [T(m0, r, i) for i in range(1, n + 1)]

def min_year_to_reach_target(m0, r, target):
    n = 1
    while T(m0, r, n) < target:
        n += 1
    return n

# Nhập dữ liệu
m0, r, n = map(float, input("Nhập m0, r, n: ").split())
n = int(n)

# Tính T(m0, r, n)
result = T(m0, r, n)
print(f"{result:.3f}")

# Dãy T(m0, r, i) từ i = 1 đến n
seq = sequence_T(m0, r, n)
print(" ".join(f"{x:.3f}" for x in seq))

# Tìm số năm cần để vượt số tiền m (tùy chọn)
m = float(input("Nhập số tiền kỳ vọng m: "))
min_n = min_year_to_reach_target(m0, r, m)
print(f"Số năm tối thiểu để vượt {m} là: {min_n}")