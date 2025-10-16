def nhan(A, c):
    return [[A[i][j] * c for j in range(len(A[0]))] for i in range(len(A))]

A = [[1,2],[3,4]]
c = 2
print("c * A =", nhan(A, c))