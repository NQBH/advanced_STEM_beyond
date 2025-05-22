#bai13
n=int(input())
dayso= list(map(float,input().split()))
max=min= dayso[0]
for i in range(0,len(dayso)):
  if dayso[i]>max:
    max=dayso[i]
  if dayso[i]<min:
    min=dayso[i]
print(max)
print(min)

#13a
a, b, c = map(float, input("Nhập ba số thực a, b, c (cách nhau bởi khoảng trắng): ").split())

so_lon_nhat = max(a, b, c)
so_nho_nhat = min(a, b, c)

print("Số lớn nhất là:", so_lon_nhat)
print("Số nhỏ nhất là:", so_nho_nhat)

#13b
n = list(map(float, input("Nhập các số thực (cách nhau bởi khoảng trắng): ").split()))

so_lon_nhat = max(n)
so_nho_nhat = min(n)

print("Số lớn nhất là:", so_lon_nhat)
print("Số nhỏ nhất là:", so_nho_nhat)

#13a
a, b, c = map(float, input("Nhập ba số thực a, b, c (cách nhau bởi khoảng trắng): ").split())
so_list = [a, b, c]

so_lon_nhat = so_list[0]
so_nho_nhat = so_list[0]

for i in so_list:
    if i > so_lon_nhat:
        so_lon_nhat = i
    if i < so_nho_nhat:
        so_nho_nhat = i

print("Số lớn nhất là:", so_lon_nhat)
print("Số nhỏ nhất là:", so_nho_nhat)


#13b
n = list(map(float, input("Nhập các số thực (cách nhau bởi khoảng trắng): ").split()))

so_lon_nhat = n[0]
so_nho_nhat = n[0]

for i in n:
    if i > so_lon_nhat:
        so_lon_nhat = i
    if i < so_nho_nhat:
        so_nho_nhat = i

print("Số lớn nhất là:", so_lon_nhat)
print("Số nhỏ nhất là:", so_nho_nhat)
print("Bài toán 13")
'''
a, b, c = map(float, input("Nhập 3 số a b c: ").split())
max_val = a if a > b and a > c else (b if b > c else c)
min_val = a if a < b and a < c else (b if b < c else c)
print("Max:", max_val, "| Min:", min_val)
'''

input_str = input("Nhập các số cách nhau bằng dấu cách: ")
numbers = list(map(float, input_str.split()))

if not numbers:
    print("Bạn chưa nhập số nào!")
else:
    max_val = numbers[0]
    min_val = numbers[0]
    
    for num in numbers:
        if num > max_val:
            max_val = num
        if num < min_val:
            min_val = num
    
    print(f"Giá trị lớn nhất: {max_val}")
    print(f"Giá trị nhỏ nhất: {min_val}")

print("Bài toán 13")
a, b, c = map(float, input("Nhập 3 số a b c: ").split())
max_val = a if a > b and a > c else (b if b > c else c)
min_val = a if a < b and a < c else (b if b < c else c)
print("Max:", max_val, "| Min:", min_val)

input_str = input("Nhập các số cách nhau bằng dấu cách: ")
numbers = list(map(float, input_str.split()))

if not numbers:
    print("Bạn chưa nhập số nào!")
else:
    max_val = numbers[0]
    min_val = numbers[0]
    
    for num in numbers:
        if num > max_val:
            max_val = num
        if num < min_val:
            min_val = num
    
    print(f"Giá trị lớn nhất: {max_val}")
    print(f"Giá trị nhỏ nhất: {min_val}")