import numpy as np
from sympy import factor
from sympy.matrices import Matrix, eye, zeros, ones, diag, GramSchmidt
from sympy.abc import a, x

print(np.__version__)

# VMC2023B1
print('# VMC2023B1')
A = Matrix([[x, a, a + 1], [a, a + 1, x], [a + 1, x, a]])
detA = A.det()
print(detA)
print(factor(detA))

# VMC2024A1B1
print('# VMC2024A1B1')
Aa = np.matrix([[1,0,1,0], [2,1,0,1], [1,0,1,0], [0,1,2,1]])
print(np.linalg.matrix_rank(Aa))
A = Matrix([[1,a + 1,a + 2,0],[a + 3,1,0,a + 2],[a + 2,0,1,a + 1],[0,a + 2,a + 3,1]])
detA = A.det()
print(detA)
print(factor(detA))