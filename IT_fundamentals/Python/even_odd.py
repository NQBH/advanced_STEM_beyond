# An
print("bài 11")
n = int(input())
nums = list(map(int, input("Nhập dãy số: ").split()))
even = len([x for x in nums if x % 2 == 0])
odd = len(nums) - even
print(f"Số chẵn: {even}")
print(f"Số lẻ: {odd}")

# Ngoc Han
n = int(input("Nhập số lượng phần tử n: "))  # Nhập số nguyên dương n
a = list(map(int, input("Nhập dãy số nguyên (cách nhau bởi dấu cách): ").split()))


so_chan = 0
so_le = 0

for i in a:
    if i % 2 == 0:
        so_chan += 1
    else:
        so_le += 1

print("Số lượng số chẵn:", so_chan)
print("Số lượng số lẻ:", so_le)

# Yen Hoa
n = int(input("Nhập số lượng phần tử: "))
numbers = list(map(int, input("Nhập dãy số cách nhau bởi khoảng trắng: ").split()))

even_count = sum(1 for num in numbers if num % 2 == 0)
odd_count = n - even_count

print(f"number of evens: {even_count}")
print(f"number of odds: {odd_count}")

# TVNK
#bai11
n=int(input("Nhap n: "))
danhsach = list(map(int, input().split()))
countchan = countle = 0
for i in range(n):
  if danhsach[i] % 2 == 0:
    countchan+=1
  else:
    countle+=1
print("number of even: ", countchan)
print("number of odd: ", countle)

# HTA
n = int(input())
numbers = list(map(int, input().split()))

even_count = sum(1 for num in numbers if num % 2 == 0)
odd_count = n - even_count

print(f"number of evens: {even_count}")
print(f"number of odds: {odd_count}")

## NTTH
print("bai 11")
n = int(input("Nhập số lượng phần tử: "))
numbers = list(map(int, input("Nhập các số nguyên, cách nhau bằng dấu cách: ").split()))

# Kiểm tra số lượng phần tử nhập vào có đúng không
if len(numbers) != n:
    print("Số lượng phần tử không đúng với giá trị n.")
else:
    evens = 0
    odds = 0

    # Duyệt qua từng số trong danh sách
    for num in numbers:
        if num % 2 == 0:
            evens += 1
        else:
            odds += 1

    # In kết quả
    print("number of evens:", evens)
    print("number of odds:", odds)

# Ngoc Lan
n = int(input())
so = list(map(int, input("Nhập n số nguyên: ").split()))
so_chan = 0
so_le = 0
for num in so:
    if num % 2 == 0:
        so_chan += 1
    else:
        so_le += 1
print(f"Số chẵn: {so_chan}")
print(f"Số lẻ: {so_le}")

# Quoc Thanh
n = int(input("nhap n "))
numbers = list(map(int, input("Nhap day so nguyen cach nhau boi khoang trang ").split()))
even_count = 0
odd_count = 0
for num in numbers:
    if num % 2 == 0:
        even_count += 1
    else:
        odd_count += 1
print(f"so chan : {even_count}")
print(f"so le : {odd_count}")

# Van Len
n = int(input())  # Nhập số lượng phần tử
numbers = list(map(int, input().split()))  # Nhập dãy số nguyên

even = 0
odd = 0

for x in numbers:
    if x % 2 == 0:
        even += 1
    else:
        odd += 1

print("number of evens:", even)
print("number of odds:", odd)

# Nhan
n = int(input("Nhập số lượng phần tử n: "))
a = list(map(int, input("Nhập dãy số nguyên (cách nhau 1 dấu cách): ").split()))
chan = 0
le = 0
for i in a:
    if i % 2 == 0:
        chan += 1
    else:
        le += 1
print("Số lượng số chẵn: ", chan)
print("Số lượng số lẻ: ", le)

# PKS
n= int(input())
numbers = list(map(int,input().split()))
so_chan=0
n= int(input())
numbers = list(map(int,input().split()))
so_chan=0
so_le=0
for i in numbers:
  if i % 2 == 0:
    so_chan += 1
  else:
    so_le += 1
print("number of so_chan:", so_chan)
print("number of so_le:", so_le)

# Nhập số lượng phần tử
n = int(input("Nhập n: "))

# Nhập dãy số nguyên cách nhau bởi dấu cách
a = list(map(int, input("Nhập dãy số: ").split()))

# Kiểm tra độ dài đầu vào
if len(a) != n:
    print("Số lượng phần tử không khớp với n!")
else:
    evens = sum(1 for x in a if x % 2 == 0)
    odds = n - evens

    print("number of evens:", evens)
    print("number of odds:", odds)

n = int(input())
ds = list(map(int, input().split()))
print("number of evens:", sum(1 for x in ds if x % 2 == 0))
print("number of odds:", n - sum(1 for x in ds if x % 2 == 0))

# Bao Ngoc
n = int(input("Nhập số lượng phần tử n:"))

numbers = list(map(int, input("Nhập các số nguyên, cách nhau bằng dấu cách:").split()))

even_count = 0
odd_count = 0

for num in numbers:
    if num % 2 == 0:
        even_count += 1
    else:
        odd_count += 1

print("number of evens:", even_count)
print("number of odds:", odd_count)

# nhap so phan tu
n = int(input("Nhap n: "))

# nhap day so bang dau cach
a = list(map(int, input("Nhap day so: ").split()))

# kiem tra do dai dau vao
if len(a) != n:
    print("so luong yu ko khop voi  n!")
else:
    evens = sum(1 for x in a if x % 2 == 0)
    odds = n - evens

    print("number of evens:", evens)
    print("number of odds:", odds)

n = int(input())              # Nhập số lượng phần tử
a = list(map(int, input("nhap n so nguyen: ").split()))  # Nhập dãy số và chuyển sang danh sách số nguyên

even = 0   # Biến đếm số chẵn
odd = 0    # Biến đếm số lẻ

for num in a:
    if num % 2 == 0:
        even += 1
    else:
        odd += 1

print("number of evens:", even)
print("number of odds:", odd)

n = int(input("Nhập số lượng phần tử: "))


a = list(map(int, input("Nhập dãy số nguyên cách nhau bởi khoảng trắng: ").split()))


even_count = 0
odd_count = 0


for num in a:
    if num % 2 == 0:
        even_count += 1
    else:
        odd_count += 1
print("number of evens:", even_count)
print("number of odds:", odd_count)