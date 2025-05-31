from math import pow

def eval_polynomial(n, a, x0): # compute P(x0) with a polynomial P of degree n & coefficients a
	ans = 0
	for i in range(n + 1):
		ans += a[i] * pow(x, i)
	return ans

t = int(input())
for _ in range(t):
	x0 = input()
	a = map(float, input().split)
	b = map(float, input().split)

	if x0 == "-inf"

	elif x0 == "inf"

	else:
		x0 = float(x0)
		P = eval_polynomial(m, a, x0)
		Q = eval_polynomial(n, b, x0)
		