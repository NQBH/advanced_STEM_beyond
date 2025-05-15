data = list(map(float, input().split()))
loi = lo = hue = 0
tong_loi = tong_lo = 0.0
for x in data:
  if x > 0:
    loi += 1
    tong_loi += x
  elif x < 0:
    lo += 1
    tong_lo += x
  else:
    hue += 1
print(loi, lo, hue)
print(f"{tong_loi} {tong_lo}")

a = list(map(float, input("nhap so thuc bang cach: ").split()))

# khoi tao diem ben sv tong
so_count_loi = so_count_lo = so_count_hue_von = 0
tong_loi = tong_lo = 0.0

# duyet phan tu danh sach
for x in a:
    if x > 0:
        so_count_loi += 1
        tong_loi += x
    elif x < 0:
        so_count_lo += 1
        tong_lo += x
    else:
        so_count_hue_von += 1

# ket qua
print(so_count_loi, so_count_lo, so_count_hue_von)
print(round(tong_loi, 2), round(tong_lo, 2))

print("Tính số tiền lời và lỗ")
sothang = int(input("Nhập số tháng cần tính: "))
loi = 0
lo = 0
hue = 0
count_lo = 0
count_loi = 0
count_hue = 0

for i in range(sothang):
    a = float(input("Nhập số tiền thu được trong tháng"))
    
    if a < 0:
        lo += a
        count_lo += 1
    elif a == 0:
        hue += a
        count_hue += 1
    else:
        loi += a
        count_loi += 1


print(f"Số tiền lỗ là: {lo} ")
print(f"Số tháng lỗ: {count_lo}")
print(f"Số tiền lời là: {loi} ")
print(f"Số tháng lời: {count_loi}")
print(f"Số tháng huề vốn: {count_hue}")

a = list(map(float, input().split()))

loi = [x for x in a if x > 0]
lo = [x for x in a if x < 0]
hue_von = [x for x in a if x == 0]

print(len(loi), len(lo), len(hue_von))
print(round(sum(loi), 2), round(sum(lo), 2))

# Nhập dãy số từ người dùng hoặc file
a = [10.5, -2.3, 3.6, 4.5, -7.41, 0, 1.23]

# Khởi tạo các biến đếm và tổng
count_profit = 0
count_loss = 0
count_zero = 0
sum_profit = 0.0
sum_loss = 0.0

# Duyệt qua dãy số
for x in a:
    if x > 0:
        count_profit += 1
        sum_profit += x
    elif x < 0:
        count_loss += 1
        sum_loss += x
    else:
        count_zero += 1

# In kết quả
print(count_profit, count_loss, count_zero)
print(round(sum_profit, 2), round(sum_loss, 2))

numbers = list(map(float, input("Nhập dãy số thực cách nhau bằng dấu cách: ").split()))
count_profit = count_loss = count_neutral = 0
sum_profit = sum_loss = 0.0
for num in numbers:
    if num > 0:
        count_profit += 1
        sum_profit += num
    elif num < 0:
        count_loss += 1
        sum_loss += num
    else:
        count_neutral += 1
print(count_profit, count_loss, count_neutral)
print(f"{sum_profit:.2f} {sum_loss:.2f}")

nhaptiencacthang = input("nhap tien cac thang:").split()
tiencacthang = [float(x) for x in nhaptiencacthang]
so_thang_loi=0
so_thang_lo=0
so_thang_hue=0
tong_tien_loi=0
tong_tien_lo=0
for i in tiencacthang:
    if i > 0:
        so_thang_loi=so_thang_loi+1
        tong_tien_loi=tong_tien_loi+i
    elif i < 0:
        so_thang_lo=so_thang_lo+1
        tong_tien_lo=tong_tien_lo+i
    else:
        so_thang_hue=so_thang_hue+1
    tong_thu_nhap= tong_tien_loi+tong_tien_lo        
print(so_thang_loi,so_thang_lo,so_thang_hue)
print(round(tong_tien_loi,2),round(tong_tien_lo,2),round(tong_thu_nhap,2))

# Nhập chuỗi số thực cách nhau bởi khoảng trắng
numbers = list(map(float, input("Nhập dãy số: ").split()))

# Khởi tạo biến đếm
profit_months = loss_months = neutral_months = 0
total_profit = total_loss = 0.0

# Xử lý từng phần tử trong danh sách
for value in numbers:
    if value > 0:
        profit_months += 1
        total_profit += value
    elif value < 0:
        loss_months += 1
        total_loss += value
    else:
        neutral_months += 1

# In kết quả
print(profit_months, loss_months, neutral_months)
print(f"{total_profit:.2f} {total_loss:.2f}")

danhsach = input("Nhập dãy số thực: ").split()
danhsach = [float(x) for x in danhsach]
so_thang_loi = 0
so_thang_lo = 0
so_thang_hue_von = 0
tong_tien_loi = 0
tong_tien_lo = 0

for so in danhsach:
    if so > 0:
        so_thang_loi += 1
        tong_tien_loi += so
    elif so < 0:
        so_thang_lo += 1
        tong_tien_lo += so
    else:
        so_thang_hue_von += 1

print(so_thang_loi, so_thang_lo, so_thang_hue_von)
print(round(tong_tien_loi, 2), round(tong_tien_lo, 2))

a = list(map(float, input().split()))
l, lo, hv, tl, tlo = 0, 0, 0, 0, 0

for x in a:
    if x > 0:
        l += 1; tl += x
    elif x < 0:
        lo += 1; tlo += x
    else:
        hv += 1

print(l, lo, hv)
print(round(tl, 2), round(tlo, 2))

data = input("Nhập các số thu nhập cách nhau bằng dấu cách: ")
nums = list(map(float, data.split()))

loi = lo = hue = 0
tong_loi = tong_lo = 0

for x in nums:
    if x > 0:
        loi += 1
        tong_loi += x
    elif x < 0:
        lo += 1
        tong_lo += x
    else:
        hue += 1

print(loi, lo, hue)
print(f"{tong_loi:.2f}", f"{tong_lo:.2f}")
print(f"{(tong_loi + tong_lo):.2f}")

a = list(map(float, input("Nhập dãy số thực cách nhau bằng dấu cách: ").split()))
so_thang_loi = so_thang_lo = so_thang_hue_von = 0
tong_loi = tong_lo = 0.0
for x in a:
    if x > 0:
        so_thang_loi += 1
        tong_loi += x
    elif x < 0:
        so_thang_lo += 1
        tong_lo += x
    else:
        so_thang_hue_von += 1
print(so_thang_loi, so_thang_lo, so_thang_hue_von)
print(round(tong_loi, 2), round(tong_lo, 2))

so = [float(x) for x in input("Nhập dãy số: ").split()]
loi = lo = hue = 0
tong_loi = tong_lo = 0
for x in so:
    if x > 0:
        loi = loi + 1
        tong_loi = tong_loi + x
    elif x < 0:
        lo = lo + 1
        tong_lo = tong_lo + x
    else:
        hue = hue + 1
tong_tat_ca = tong_loi + tong_lo 
print(loi, lo, hue)
print(round(tong_loi, 2), round(tong_lo, 2))
print("Tổng:", round(tong_tat_ca, 2))

import pandas as pd
# Nhập dãy số tiền
so_tien = [10.5, -2.3, 3.6, 4.5, -7.41, 0, 1.23]
# Tạo DataFrame
df = pd.DataFrame(so_tien, columns=['Tiền'])

# Đếm số tháng lời, lỗ, huề vốn
thang_loi = len(df[df['Tiền'] > 0])
thang_lo = len(df[df['Tiền'] < 0])
thang_hue_von = len(df[df['Tiền'] == 0])

# Tính tổng tiền lời và tổng tiền lỗ
tong_tien_loi = df[df['Tiền'] > 0]['Tiền'].sum()
tong_tien_lo = df[df['Tiền'] < 0]['Tiền'].sum()

# Xuất kết quả
print(f"Số tháng lời: {thang_loi}, Số tháng lỗ: {thang_lo}, Số tháng huề vốn: {thang_hue_von}")
print(f"Tổng tiền lời: {tong_tien_loi:.2f}, Tổng tiền lỗ: {tong_tien_lo:.2f}")

def thong_ke_loi_lo(ds_thu_nhap):
    so_thang_loi = so_thang_lo = so_thang_hue = 0
    tong_loi = tong_lo = 0.0

    for tien in ds_thu_nhap:
        if tien > 0:
            so_thang_loi += 1
            tong_loi += tien
        elif tien < 0:
            so_thang_lo += 1
            tong_lo += tien
        else:
            so_thang_hue += 1

    return so_thang_loi, so_thang_lo, so_thang_hue, tong_loi, tong_lo

# Nhập dãy số từ bàn phím (cách nhau bởi dấu cách)
ds = list(map(float, input("Nhập dãy số tiền từng tháng, cách nhau bởi dấu cách: ").split()))

# Gọi hàm xử lý
loi, lo, hue, tong_loi, tong_lo = thong_ke_loi_lo(ds)
 
# Xuất kết quả
print(f"{loi}{lo}{hue}")
print(f"{round(tong_loi, 2)}{round(tong_lo, 2)}")

a = list(map(float, input().split()))
l, lo, hv, tl, tlo = 0, 0, 0, 0, 0

for x in a:
    if x > 0:
        l += 1; tl += x
    elif x < 0:
        lo += 1; tlo += x
    else:
        hv += 1
    tong=tl+tlo
print(l, lo, hv)
print(round(tl, 2), round(tlo, 2),round(tong,2))

a=[10.5,-2.3,3.6,4.5,-7.41,0,1.23]
profit_months = 0
total_profit = 0.0
loss_months = 0
total_loss = 0.0
neutral_months = 0
for x in a:
  if x > 0:
    profit_months += 1
    total_profit += x
  elif x < 0:
    loss_months += 1
    total_loss += abs(x)
  else: 
    neutral_months += 1
 # ket qua
print("số tháng lời:", profit_months)
print("số tháng lỗ:", loss_months)
print("số tháng hòa vốn:", neutral_months)
print("tổng tiền lời:", total_profit)
print("tổng tiền lỗ:", total_loss)
