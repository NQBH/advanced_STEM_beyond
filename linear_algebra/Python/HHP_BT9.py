import numpy as np

m = int(input("Nhập số hàng: "))
n = int(input("Nhập số cột: "))
A = np.zeros((m,n))
for i in range (m):
    for j in range(n):
      A[i][j] = int(input(f"Nhập phần tử A[{i}][{j}]: "))
print(A)
print()
if m!=n:
   print("Ma trận này không phải là ma trận vuông")
else:
   duongcheo = True
   tamgiactren =True
   tamgiacduoi = True
   doixung = True
   for i in range(m):
      for j in range(n):
        if i != j and A[i][j]!=0:
            duongcheo = False
        if i > j and A[i][j] != 0:
            tamgiactren = False
        if i < j and A[i][j] != 0:
           tamgiacduoi = False
        if A[i][j]!=A[j][i]:
           doixung = False
if duongcheo:
    print("Đây là ma trận đường chéo")
elif tamgiactren:
      print("Đây là ma trận tam giác trên")
elif tamgiacduoi:
      print("Đây là ma trận tam giác dưới")
elif doixung:
      print("Đây là ma trận đối xứng")
else:
      print("Đây không phải là ma trận thuộc các loại trên!!")
