def M(m0, r, m, n):
    return m0 * (1 + r / (100 * m)) ** (m * n)

# Nhập đầu vào
m0, r, m, n = map(float, input("Nhập m0, r, m, n (cách nhau bởi dấu cách): ").split())
m = int(m)
n = int(n)

# (a) Tính M(m0, r, m, n)
M_final = M(m0, r, m, n)
print(f"{M_final:.3f}")

# (b) In dãy M(m0, r, m, i) từ i = 1 đến n
for i in range(1, n + 1):
    print(f"{M(m0, r, m, i):.3f}", end=' ')
print()

# (c) Tìm số năm nhỏ nhất sao cho M vượt một số tiền kỳ vọng M_expect
M_expect = float(input("Nhập số tiền kỳ vọng M: "))
year = 1
while M(m0, r, m, year) <= M_expect:
    year += 1
print(f"Sau {year} năm thì số tiền vượt {M_expect}")

print("Bài 10")
tien_goc, lai_suat, ky_han, so_nam = map(float, input("Nhập m0, r, m, n (cách nhau bởi dấu cách): ").split())
ky_han = int(ky_han)
so_nam = int(so_nam)
lai_moi_ky = lai_suat / ky_han
so_ky = ky_han * so_nam
tien_nhan_duoc = tien_goc * (1 + lai_moi_ky/100)**so_ky
print(f"Sau {so_nam} năm, nhận được: {tien_nhan_duoc:,.0f} đồng")
muc_tieu = float(input("Nhập số tiền mục tiêu (bỏ qua nếu không cần): "))
if muc_tieu > 0:
  nam = 1
  while True:
    tien = tien_goc * (1 + lai_moi_ky/100)**(ky_han*nam)
    if tien >= muc_tieu:
      break
    nam += 1
  print(f"Cần {nam} năm để đạt {muc_tieu:,.0f} đồng")

def M(m0, r, m, n):
    return m0 * (1 + r / (100 * m)) ** (m * n)

def sequence_M(m0, r, m, n):
    return [M(m0, r, m, i) for i in range(1, n + 1)]

def min_year_to_reach_target(m0, r, m, target):
    n = 1
    while M(m0, r, m, n) < target:
        n += 1
    return n

# --- Nhập từ bàn phím ---
m0, r, m, n = map(float, input("Nhập m0, r, m, n (phân cách bởi dấu cách): ").split())
m = int(m)
n = int(n)

# (a) Tính T = M(m0, r, m, n)
T = M(m0, r, m, n)
print(f"T = {T:.2f}")

# (b) In dãy số {M(m0, r, m, i)} từ i = 1 đến n
dãy = sequence_M(m0, r, m, n)
print("Dãy số:", ' '.join(f"{x:.2f}" for x in dãy))

# (c) Tính số năm tối thiểu để vượt số tiền kỳ vọng M
target = float(input("Nhập số tiền kỳ vọng M: "))
min_year = min_year_to_reach_target(m0, r, m, target)
print(f"Số năm tối thiểu để vượt {target} là: {min_year}")

def M(m0, r, m, n):
    """Tính số tiền sau n năm với lãi kép nhập m kỳ/năm."""
    return m0 * (1 + r / (100 * m))**(m * n)
m0, r, m, n = map(float, input("Nhập m0, r, m, n (phân cách bởi dấu cách): ").split())
m, n = int(m), int(n)
T = M(m0, r, m, n)
print(f"(a) T = {T:.2f}")
print("(b) Dãy số tiền nhận được qua từng năm:")
for i in range(1, n + 1):
    print(f"  Năm {i}: {M(m0, r, m, i):.2f}")
target = float(input("(c) Nhập số tiền kỳ vọng M: "))
i = 1
while True:
    if M(m0, r, m, i) > target:
        print(f"  Số năm nhỏ nhất để vượt qua M là: {i}")
        break
    i += 1

# Hàm tính M(m0, r, m, n)
def M(m0, r, m, n):
    return m0 * (1 + r / (100 * m)) ** (m * n)

# Nhập từ bàn phím
m0, r, m, n = map(float, input("Nhập lần lượt m0, r, m, n (cách nhau bởi khoảng trắng): ").split())
m = int(m)
n = int(n)

# (a) Tính và in ra M(m0, r, m, n)
Mn = M(m0, r, m, n)
print(f"{round(Mn, 3)}")

# (b) In ra dãy {M(m0, r, m, i)} từ i = 1 đến i = n
for i in range(1, n + 1):
    print(round(M(m0, r, m, i), 3), end=" ")
print()

# (c) Nhập M kỳ vọng, tìm số năm đầu tiên đạt được
target = float(input("Nhập số tiền kỳ vọng M: "))
i = 1
while M(m0, r, m, i) < target:
    i += 1
print(f"Sau {i} năm, tổng tiền vượt {target}")
print(f"Số tiền lúc đó là: {round(M(m0, r, m, i), 3)}")

# Ham tinh M(m0, r, m, n)
def M(m0, r, m, n):
    return m0 * (1 + r / (100 * m)) ** (m * n)

# nhap tu ban phim
m0, r, m, n = map(float, input("Nhập lần lượt m0, r, m, n (cách nhau bởi khoảng trắng): ").split())
m = int(m)
n = int(n)

# (a) tinh va in ra M(m0, r, m, n)
Mn = M(m0, r, m, n)
print(f"{round(Mn, 3)}")

# (b) in ra day {M(m0, r, m, i)} từ i = 1 đến i = n
for i in range(1, n + 1):
    print(round(M(m0, r, m, i), 3), end=" ")
print()

# (c) nhap m ki vong, tìm số năm đầu tiên đạt được
target = float(input("Nhập số tiền kỳ vọng M: "))
i = 1
while M(m0, r, m, i) < target:
    i += 1
print(f"Sau {i} năm, tổng tiền vượt {target}")
print(f"Số tiền lúc đó là: {round(M(m0, r, m, i), 3)}")