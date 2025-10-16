def chuyen_vi(A):
    m, n = len(A), len(A[0])
    return [[A[i][j] for i in range(m)] for j in range(n)]
A = [[1,2,3],[4,5,6]]
At = chuyen_vi(A)
print("Ma trận chuyển vị A^T:")
for row in At: print(row)
