import numpy as np
print(np.__version__)
A = np.matrix([[1,0,1,0], [2,1,0,1], [1,0,1,0], [0,1,2,1]])
print(np.linalg.matrix_rank(A))

from sympy.matrices import Matrix, eye, zeros, ones, diag, GramSchmidt

# VMC2023B1
from sympy.abc import x, a
A = Matrix([[x, a, a + 1], [a, a + 1, x], [a + 1, x, a]])
print(A.det())