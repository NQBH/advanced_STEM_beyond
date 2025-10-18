n = int(input("Nhập kích thước n của ma trận vuông: "))

print("Nhập các phần tử của ma trận (mỗi hàng cách nhau bằng Enter):")
A = []
for i in range(n):
    row = list(map(float, input().split()))
    A.append(row)

is_diagonal = True
is_upper = True
is_lower = True
is_symmetric = True

for i in range(n):
    for j in range(n):
        if i != j and A[i][j] != 0:    
            is_diagonal = False        
        if i > j and A[i][j] != 0:     
            is_upper = False           
        if i < j and A[i][j] != 0:     
            is_lower = False           
        if A[i][j] != A[j][i]:         
            is_symmetric = False

print("\nKết quả kiểm tra:")
if is_diagonal:
    print("- Ma trận đường chéo")
if is_upper:
    print("- Ma trận tam giác trên")
if is_lower:
    print("- Ma trận tam giác dưới")
if is_symmetric:
    print("- Ma trận đối xứng")
if not (is_diagonal or is_upper or is_lower or is_symmetric):
    print("- Ma trận không thuộc các loại trên")
