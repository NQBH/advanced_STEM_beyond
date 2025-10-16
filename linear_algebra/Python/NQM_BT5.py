def swap(A):
    return [[A[j][i] for j in range(len(A))] for i in range(len(A[0]))]

A = [[1,2,3],[4,5,6]]
print("A^T =", swap(A))
