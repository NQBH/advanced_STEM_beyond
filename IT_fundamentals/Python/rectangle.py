#B5
def min_rectangle_area(points):
    if not points:
        return 0
    
    min_x = min(p[0] for p in points)
    max_x = max(p[0] for p in points)
    min_y = min(p[1] for p in points)
    max_y = max(p[1] for p in points)
    
    width = max_x - min_x
    height = max_y - min_y
    
    return width * height
    
n = int(input("Nhập số lượng điểm: "))
points = []
for i in range(n):
    x, y = map(int, input(f"Nhập tọa độ điểm {i+1} (x y): ").split())
    points.append((x, y))

area = min_rectangle_area(points)
print(f"Diện tích hình chữ nhật nhỏ nhất bao phủ tất cả điểm là: {area}")

# Bài 5: 
n = int(input("Nhập số lượng điểm:"))
i = 0
x_min = y_min = float('inf')
x_max = y_max = float('-inf')

while i < n:
    x, y = map(int, input(f"Nhập tọa độ điểm thứ {i+1} (x y): ").split())

    if x < x_min: x_min = x
    if x > x_max: x_max = x
    if y < y_min: y_min = y
    if y > y_max: y_max = y

    i += 1

chieu_rong = x_max - x_min
chieu_cao = y_max - y_min
dien_tich = chieu_rong * chieu_cao
print("Diện tích hình chữ nhật nhỏ nhất phủ tất cả các điểm là:", dien_tich)

n = int(input("Nhập số điểm: "))

x_min = y_min = float('inf')
x_max = y_max = float('-inf')

for _ in range(n):
    x, y = map(int, input("Nhập x y: ").split())
    if x < x_min: x_min = x
    if x > x_max: x_max = x
    if y < y_min: y_min = y
    if y > y_max: y_max = y

dien_tich = (x_max - x_min) * (y_max - y_min)
print("Diện tích hình chữ nhật là:", dien_tich)

#bai5
n= int(input())
x= []
y= []
for i in range(n):
    xi, yi = map(int, input().split())
    x.append(xi)
    y.append(yi)

min_x = x[0]
max_x = x[0]
min_y = y[0]
max_y = y[0]

for i in range(1,n):
    if x[i] < min_x:
        min_x = x[i]
    if x[i] > max_x:
        max_x = x[i]
    if y[i] < min_y:
        min_y = y[i]
    if y[i] > max_y:
        max_y = y[i]
s= (max_x-min_x)*(max_y-min_y)
print(s)

#bai 5
n = int(input("Nhập số điểm: "))

ds_x = [0] * n  
ds_y = [0] * n  

for i in range(n):
    x, y = map(int, input("Nhập điểm (x y): ").split())
    ds_x[i] = x    
    ds_y[i] = y    

rộng = max(ds_x) - min(ds_x)
cao = max(ds_y) - min(ds_y)

diện_tích = rộng * cao

print("Diện tích nhỏ nhất là:", diện_tích)

n = int(input("Nhập số điểm: "))

x_min = y_min = float('inf')
x_max = y_max = float('-inf')

for _ in range(n):
    x, y = map(int, input("Nhập x y: ").split())
    if x < x_min: x_min = x
    if x > x_max: x_max = x
    if y < y_min: y_min = y
    if y > y_max: y_max = y

dien_tich = (x_max - x_min) * (y_max - y_min)
print("Diện tích hình chữ nhật là:", dien_tich)