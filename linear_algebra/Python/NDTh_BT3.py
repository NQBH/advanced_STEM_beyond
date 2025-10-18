def nhan_vo_huong(A,c):
    return [[A[i][j] * c for j in range(len(A[0]))] for i in range(len(A))]
A = [[1, 2, 3], [4, 5, 6]]
c = 3
C = nhan_vo_huong(A, c)
print(f"{c} * A =")     
for row in C:
    print(row)    