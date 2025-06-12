import numpy as np

a = np.array([float(x) for x in input().split()])
b = np.array([float(x) for x in input().split()])

if len(a) != len(b):
	print("Error: Incompatible sizes.")
else:
	ans = 0
	for i in range(len(a)):
		ans += a[i] * b[i]
	print("a * b =", ans)