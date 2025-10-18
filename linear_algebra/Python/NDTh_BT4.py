def nhan_hai_ma_tran(A, B):
    m, n, p = len(A), len(A[0]), len(B[0])
    C = [[0]*p for _ in range(m)]
    for i in range(m):
        for j in range(p):
            for k in range(n):
                C[i][j] += A[i][k] * B[k][j]
    return C

A = [[1,2,3],[4,5,6]]
B = [[7,8],[9,10],[11,12]]
C = nhan_hai_ma_tran(A,B)
print("A x B =")
for row in C: print(row)
