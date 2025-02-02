import numpy as np
print(np.__version__)
A = np.matrix([[1,0,1,0], [2,1,0,1], [1,0,1,0], [0,1,2,1]])
print(np.linalg.matrix_rank(A))