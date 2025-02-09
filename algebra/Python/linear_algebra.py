# source: \cite{Tsukada_Kobayashi_Kaneko_Takahasi_Shirayanagi_Noguchi2023}. {\sc Makoto Tsukada, Yuji Kobayashi, Hiroshi Kaneko, Sin-Ei Takahasi, Kiyoshi Shirayanagi, Masato Noguchi}. Linear Algebra with Python: Theory \& Applications

# Chap. 1: Mathematics \& Python
for P in [True, False]:
	print( P , not P)

# Chap. 4: Matrices

## 4.1. Matrix Operations
from numpy import array

A = [[1 , 2 , 3] , [4 , 5 , 6]]
print(A)
A = array(A) # cast list A to an array A
print(A)
print(list(A))

L = A.tolist(); # make list from array
print(L)

B = A.copy() # copying A, make another array B with same contents
print(B)
print(A == B)
print((A == B).all())
B[0, 1] = 1
print((A == B).all())

A = array([1, 2, 3])
print(A)
B = A.reshape((1, 3))
print(B)
C = B.reshape((3, 1))
print(C)
D = C.reshape((3,))
print(D)
A[0] = 0
print(A)
print(B[0, 0], C[0, 0], D[0])

# add matrices
A = array([[1 , 2 , 3], [4 , 5 , 6]])
B = array([[1 , 3 , 5], [2 , 4 , 6]])
print(A + B)

# scalar multiplication of a matrix
print(2 * A)
print(A / 2)
print(A * B)
print(0 * A)
print(-1 * A)

# output calculation problems of matrices in a form of a code in math mode of LaTeX
from numpy.random import seed , randint , choice
from sympy import Matrix , latex

seed(2025)
m, n = randint(2, 4, 2)
X = [-3, -2, -1, 1, 2, 3, 4, 5]
A = Matrix(choice(X, (m, n)))
B = Matrix(choice(X, (m, n)))
print(f'{latex(A)} + {latex(B)} = ')

## 4.2. Matrices & Linear Mappings