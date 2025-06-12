import numpy as np
rows = int(input("Nhập số hàng của ma trận: "))
cols = int(input("Nhập số cột của ma trận: "))

matrix_elements = []
for i in range(rows):
    row = input(f"Nhập các phần tử của hàng {i+1}, cách nhau bằng dấu cách: ").split()
    row = [float(x) for x in row]
    if len(row) != cols:
        print("Số phần tử không đúng số cột đã nhập. Vui lòng nhập lại.")
        while len(row) != cols:
            row = input(f"Nhập đúng {cols} phần tử cho hàng {i+1}: ").split()
            row = [float(x) for x in row]
    matrix_elements.append(row)
matrix = np.array(matrix_elements)
tong = np.sum(matrix)
tong_binh_phuong = np.sum(matrix ** 2)
tong_lap_phuong = np.sum(matrix ** 3)
print("Tổng các phần tử trong ma trận:", tong)
print("Tổng bình phương các phần tử:", tong_binh_phuong)
print("Tổng lập phương các phần tử:", tong_lap_phuong)