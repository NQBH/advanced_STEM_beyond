import numpy as np

# Hàm chuyển vị sử dụng NumPy
def transpose_numpy(matrix):
    arr = np.array(matrix)
    transposed = arr.T 
    return transposed.tolist() 

matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

transposed = transpose_numpy(matrix)
print("Ma trận gốc:")
print(np.array(matrix))

print("\nMa trận chuyển vị:")
print(transposed)