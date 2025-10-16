
X = int(input("Nhập số hàn ma trận A: "))
Y = int(input("Nhập số cột ma trận A: "))

print("Nhập ma trận A (mỗi hàng phải cách nhau bởi dòng mới):")
A = []
for i in range(X):
    row = list(map(float, input(f"Hàng {i+1}: ").split()))
    A.append(row)

print("Nhập vector b (mỗi phần tử phsi cách nhau bởi dấu cach):")
b = list(map(float, input().split()))

if len(b) != X:
    print("Impossible")
else:
   
    Ab = []
    for i in range(X):
        Ab.append(A[i] + [b[i]])

    print("Ma trận bổ sung [A|b]:")
    for row in Ab:
        print(row)
