# Bt1:Nhập xuất ma trận
m = int(input("Nhap so hang: "))
n= int(input("Nhap so cot: "))

A = []
print("Nhap cac phần tu ma tran:")
for i in range(m):
    row = list(map(float, input().split()))
    A.append(row)

print("Ma tran A:")
for row in A:
    print(row)
