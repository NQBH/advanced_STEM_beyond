from __future__ import print_function
import numpy as np
from time import time # for comparing running time
d, N = 1000, 10000 # dimension, number of training points
X = np.random.randn(N, d) # N d-dimensional points
x = np.random.randn(d)
z = np.random.randn(d)

# naively compute square distance between 2 vectors
def dist_pp(z, x):
	d = z - x.reshape(z.shape) # force x & z to have same dims
	return np.sum(d*d)

# from 1 point to each point in a set, naive
def dist_ps_naive(z, X):
	N = X.shape[0]
	res = np.zeros((1, N))
	for i in range(N):
		res[0][i] = dist_pp(z, X[i])
	return res

# from 1 point to each point in a set, fast
def dist_ps_fast(z, X):
	X2 = np.sum(X*X, 1) # square of l2 norm of each X[i], can be precomputed
	z2 = np.sum(z*z) # square of l2 norm of z
	return X2 + z2 - 2*X.dot(z) # z2 can be ignored

t1 = time()
D0 = dist_pp(z, x)
print('Euclidean distance, running time:', time() - t1, 's')

t1 = time()
D1 = dist_ps_naive(z, X)
print('naive point2set, running time:', time() - t1, 's')

t1 = time()
D2 = dist_ps_fast(z, X)
print('fast point2set, running time:', time() - t1, 's')
print('Result difference:', np.linalg.norm(D1 - D2))