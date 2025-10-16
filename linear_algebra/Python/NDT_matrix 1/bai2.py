def cong_tru_ma_tran( A,B):
   m , n = len(A), len(A[0])
   C_cong = [[A[i][j] + B[i][j] for j in range(n)] for i in range(m)]
   C_tru = [[A[i][j] - B[i][j] for j in range(n)] for i in range(m)]
   return C_cong, C_tru
A = [[1, 2, 3], [4, 5, 6]]
B = [[7, 8, 9], [10, 11, 12]]
C_cong, C_tru = cong_tru_ma_tran(A, B)
print("A + B =")    
for row in C_cong:
    print(row)
print("A - B =")
for row in C_tru:
    print(row)
