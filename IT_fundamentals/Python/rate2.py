m, r, n = map(float, input().split())
n = int(n)
tien = 0
for i in range(1, n+1):
  tien = (tien + m) * (1+ r/100)
  print(f"Năm {i}: {tien:,.0f} đồng")
mt = float(input("Nhập tiền mục tiêu (0 để bỏ qua): "))
if mt > 0:
  nam = 0
  tien = 0
  while tien < mt:
    nam += 1
    tien = (tien + m) * (1 + r/100)
  print(f"Cần {nam} năm để đạt {mt:,.0f} đồng")

def M(m0, r, n):
    return m0 * (100 + r) / r * (((1 + r / 100) ** n) - 1)

# (a), (b): Tính và in dãy M qua từng năm
def tinh_day_M(m0, r, n):
    return [round(M(m0, r, i), 3) for i in range(1, n + 1)]

# (c): Tìm số năm nhỏ nhất sao cho M(m0, r, n) >= m
def tim_n_de_vuot_m(m0, r, m):
    n = 1
    while M(m0, r, n) < m:
        n += 1
    return n

# --- Dữ liệu mẫu ---
m0 = 125000000     # số tiền gửi mỗi năm
r = 4.9            # lãi suất %
n = 5              # số năm gửi

# (a) Tính tổng sau n năm
tong_tien = M(m0, r, n)
print("M(m0, r, n) =", round(tong_tien, 3))

# (b) In dãy tiền tích lũy qua từng năm
day_M = tinh_day_M(m0, r, n)
print("Dãy M(m0, r, i) từ 1 đến n:")
print(day_M)

# (c) Với một số tiền m, tìm số năm tối thiểu để vượt qua
m = 723102450.785
n_can = tim_n_de_vuot_m(m0, r, m)
print("Số năm để vượt số tiền m là:", n_can)

# Hàm tính M(m0, r, n)
def M(m0, r, n):
    return (m0 * (100 + r) / r) * (((1 + r / 100) ** n) - 1)

# Nhập m0, r, n
m0, r, n = map(float, input("Nhập m0, r, n (cách nhau bởi dấu cách): ").split())
n = int(n)

# (a) Tính M sau n năm
Mn = M(m0, r, n)
print(f"Số tiền sau {n} năm là: {round(Mn, 3)}")

# (b) Xuất ra dãy M(m0, r, i) với i từ 1 đến n
print("Dãy số tiền sau mỗi năm:")
for i in range(1, n + 1):
    Mi = M(m0, r, i)
    print(f"Năm {i}: {round(Mi, 3)}")

# (c) Tìm năm đầu tiên M vượt qua số tiền kỳ vọng m
m = float(input("Nhập số tiền kỳ vọng m: "))
i = 1
while M(m0, r, i) < m:
    i += 1

print(f"Sau {i} năm thì tổng số tiền vượt qua {m}.")
print(f"Số tiền nhận được lúc đó là: {round(M(m0, r, i), 3)}")

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

print("Tính tiền gửi")
m0, r, n = map(float, input().split())
n = int(n)
T = m * (100+r)/r*(((1+r/100)**n)-1)
print(round(T,3))
for i in range(1,n+1):
  Ti = m * (100+r)/r*(((1+r/100)**n)-1)
  print(round(Ti,3))
m = input()

m0, r, n = map(float, input().split())
n = int(n)
Tong_von_va_lai = (m0 * (100 + r)) / r * ((1 + r / 100) ** n - 1)
print("Tong_von_va_lai =", round(Tong_von_va_lai, 3))
print("Dãy số tiền sau từng năm: ")
for i in range(1, n + 1):
    M = (m0 * (100 + r)) / r * ((1 + r / 100) ** i - 1)
    print(f"Năm {i}: {round(M, 3)}")
m = float(input("Nhập số tiền kỳ vọng m: "))
i = 1
while True:
    M = (m0 * (100 + r)) / r * ((1 + r / 100) ** i - 1)
    if M > m:
        print(f"Số năm tối thiểu để vượt số tiền kỳ vọng là: {i}")
        break
    i += 1


def M(m0, r, n):
    return (m0 * (100 + r) / r) * (((1 + r / 100) ** n) - 1)
m0, r, n = map(float, input().split())
n = int(n)

# (a) Tính M(m0, r, n)
ket_qua = M(m0, r, n)
print(f"{ket_qua:.3f}")

# (b) Xuất dãy {M(m0, r, i)} từ i = 1 đến n
for i in range(1, n + 1):
    print(f"{M(m0, r, i):.3f}", end=' ')
print()

# (c) Nhập thêm m để tính sau bao nhiêu năm thì vượt m
m = float(input("Nhập số tiền kỳ vọng m: "))
i = 1
while M(m0, r, i) <= m:
    i += 1
print(f"Số năm để vượt m: {i}")

nhap= input().split()
m0= float(nhap[0])
r= float(nhap[1])
n= int(nhap[2])
T = (m0 * (100 + r)) / r * ((1 + r / 100) ** n - 1)
print("Tong von va lai =", round(T, 3))
for i in range(1, n + 1):
    M= (m0 * (100+r))/r * ((1 + r / 100) ** i - 1)
    print(round(M, 3))
m=float(input("nhap so tien ky vong:"))
i=1
while True:
    
    M = (m0 * (100 + r)) / r * ((1 + r / 100) ** i - 1)
    if M >= m:
        break
    i += 1
print(i)

def M(m, r, n):
    return m * (100 + r) / r * ((1 + r / 100)**n - 1)

def main():
    m0, r, n_val = map(float, input().split())
    n = int(n_val)

    print(f"{M(m0, r, n):.3f}")
    print(", ".join([f"{M(m0, r, i):.3f}" for i in range(1, n + 1)]))

if __name__ == "__main__":
    main()

m = input()


    # Hàm tính M(m0, r, n)
def M(m0, r, n):
    return (m0 * (100 + r) / r) * (((1 + r / 100) ** n) - 1)

# Nhập m0, r, n
m0, r, n = map(float, input("Nhập m0, r, n (cách nhau bởi dấu cách): ").split())
n = int(n)

# (a) Tính M sau n năm
Mn = M(m0, r, n)
print(f"Số tiền sau {n} năm là: {round(Mn, 3)}")

# (b) Xuất ra dãy M(m0, r, i) với i từ 1 đến n
print("Dãy số tiền sau mỗi năm:")
for i in range(1, n + 1):
    Mi = M(m0, r, i)
    print(f"Năm {i}: {round(Mi, 3)}")

# (c) Tìm năm đầu tiên M vượt qua số tiền kỳ vọng m
m = float(input("Nhập số tiền kỳ vọng m: "))
i = 1
while M(m0, r, i) < m:
    i += 1

print(f"Sau {i} năm thì tổng số tiền vượt qua {m}.")
print(f"Số tiền nhận được lúc đó là: {round(M(m0, r, i), 3)}")

def compute_total(m0, r, n):
    rate = r / 100
    return m0 * ((1 + rate) ** n - 1) / rate

def solve_bai_toan_9(m0, r, n, target_m=None):
    print(f"Dữ liệu đầu vào: m0 = {m0}, r = {r}, n = {n}")
    
    # Tính M(m0, r, n)
    total = compute_total(m0, r, n)

    # In tổng tiền sau n năm
    print(f"\n Tổng tiền sau {n} năm: {total:.3f} đồng")

    # Tính dãy M(m0, r, i) từ 1 đến n
    print("\n Dãy số tiền qua từng năm:")
    for i in range(1, n + 1):
        year_total = compute_total(m0, r, i)
        print(f"Năm {i}: {year_total:.3f}")

    # Nếu có nhập số tiền m, tìm năm đầu tiên vượt m
    if target_m is not None:
        i = 1
        while True:
            value = compute_total(m0, r, i)
            if value >= target_m:
                print(f"\n Sau {i} năm, số tiền vượt {target_m} đồng (được {value:.3f})")
                break
            i += 1

#  Gọi hàm với dữ liệu mẫu
solve_bai_toan_9(125000000, 4.9, 5, target_m=1000000000)

nhap= input().split()
m0= float(nhap[0])
r= float(nhap[1])
n= int(nhap[2])
T = (m0 * (100 + r)) / r * ((1 + r / 100) ** n - 1)
print("Tong von va lai =", round(T, 3))
for i in range(1, n + 1):
    M= (m0 * (100+r))/r * ((1 + r / 100) ** i - 1)
    print(round(M, 3))
m=float(input("nhap so tien ky vong:"))
i=1
while True:
    M = (m0 * (100 + r)) / r * ((1 + r / 100) ** i - 1)
    if M >= m:
        break
    i += 1
print(i)

 # ham tinh M(m0, r, n)
def M(m0, r, n):
    return (m0 * (100 + r) / r) * (((1 + r / 100) ** n) - 1)

# Nhap m0, r, n
m0, r, n = map(float, input("Nhập m0, r, n (cách nhau bởi dấu cách): ").split())
n = int(n)

# nhap a Tinh M sau n năm
Mn = M(m0, r, n)
print(f"Số tiền sau {n} năm là: {round(Mn, 3)}")

# nhap b Xuat ra day M(m0, r, i)  i từ 1 đến n
print("Dãy số tiền sau mỗi năm:")
for i in range(1, n + 1):
    Mi = M(m0, r, i)
    print(f"Năm {i}: {round(Mi, 3)}")

# nhap c nam dau tien M vuot qua so tien mong muon m
m = float(input("Nhập số tiền kỳ vọng m: "))
i = 1
while M(m0, r, i) < m:
    i += 1

print(f"Sau {i} năm thì tổng số tiền vượt qua {m}.")
print(f"Số tiền nhận được lúc đó là: {round(M(m0, r, i), 3)}")