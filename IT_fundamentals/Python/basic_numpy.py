import numpy as np

a = np.array([float(x) for x in input("Nhập các phần tử của mảng a, cách nhau bằng dấu cách: ").split()])
b = np.array([float(x) for x in input("Nhập các phần tử của mảng b, cách nhau bằng dấu cách: ").split()])

len_a = len(a)
len_b = len(b)
print("Chiều dài của mảng a:", len_a )
print("Chiều dài của mảng b:", len_b)

if len_a == len_b:
    tong = a + b
    hieu = a - b
    tich_elementwise = a * b
    thuong_elementwise = a / b
    print("Tổng hiệu của 2 mảng:", tong)
    print("Hiệu của 2 mảng:", hieu)
    print("Tích elementwise của 2 mảng:", tich_elementwise)
    print("Thương elementwise của 2 mảng:", thuong_elementwise)
else:
    print("Hai mảng có chiều dài không bằng nhau, không thể thực hiện các phép tính trên.")

# 2
arr = np.array([float(x) for x in input("Nhập các phần tử của mảng, cách nhau bằng dấu cách: ").split()])
tong_binh_phuong = np.sum(arr ** 2)
tong_lap_phuong = np.sum(arr ** 3) 

print("Tổng bình phương của các phần tử:", tong_binh_phuong)
print("Tổng lập phương của các phần tử:", tong_lap_phuong)

#bai 2
import numpy as np
arr_input = input("Nhập các phần tử của mảng: ")
arr = np.array(list(map(float, arr_input.strip().split())))
tong_binh_phuong = np.sum(arr ** 2)
tong_lap_phuong = np.sum(arr ** 3)
print("Tổng bình phương các phần tử:", tong_binh_phuong)
print("Tổng lập phương các phần tử:", tong_lap_phuong)

arr = np.array(list(map(float, input("Nhập các phần tử của mảng, cách nhau bởi dấu cách: ").split())))

tong_binh_phuong = np.sum(arr ** 2)
tong_lap_phuong = np.sum(arr ** 3)

print("Tổng bình phương các phần tử:", tong_binh_phuong)
print("Tổng lập phương các phần tử:", tong_lap_phuong)

import numpy as np

arr = np.array(list(map(int, input("Nhập các phần tử của mảng, cách nhau bởi dấu cách: ").split())))

tong_binh_phuong = np.sum(arr ** 2)

tong_lap_phuong = np.sum(arr ** 3)

print("Tổng bình phương các phần tử:", tong_binh_phuong)
print("Tổng lập phương các phần tử:", tong_lap_phuong)

import numpy as np
arr = np.array(list(map(int, input("Nhập các phần tử của mảng, cách nhau bởi dấu cách: ").split())))
sum_of_squares = np.sum(arr ** 2)
sum_of_cubes = np.sum(arr ** 3)
print("Tổng bình phương:", sum_of_squares)
print("Tổng lập phương:", sum_of_cubes)

import numpy as np

arr = np.array([1, 2, 3])

print("Tổng bình phương:", np.sum(arr**2))
print("Tổng lập phương:", np.sum(arr**3))

import numpy as np

array = np.array(list(map(float, input("Nhập các phần tử: ").split())))


Tong_binh_phuong = np.sum(array ** 2)
Tong_lap_phuong = np.sum (array ** 3)

print("Tổng bình phương:", Tong_binh_phuong)
print("Tổng lập phương:", Tong_lap_phuong)

import numpy as np

a = np.array([1, 2, 3])
print(np.sum(a**2))  # Tổng bình phương
print(np.sum(a**3))  # Tổng lập phương