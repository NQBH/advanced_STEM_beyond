# compute permutation P_n = n!
def P(n):
	P = 1 # P_0 = P_1 = 1
	for i in range(2, n + 1):
		P *= i
	return P
# compute arrangement A_n^k = n! / (n - k)! = n(n - 1)...(n - k + 1)
def A(n, k):
	A = 1
	for i in range(n - k + 1, n + 1):
		A *= i
	return A
# compute combination C_n^k = n! / (k!(n - k)!) = A_n^k / k!
def C(n, k):
	return A(n, k) // P(k)
# compute Catalan number
def Catalan(n): # C_n = C_{2n}^n / (n + 1)
	return C(2 * n, n) // (n + 1)

def Catalan_1(n): # C_n = (2n)! / (n!(n + 1)!)
	return P(2 * n) // (P(n) * P(n + 1))

def Catalan_2(n): # C_n = C_{2n}^n - C_{2n}^{n + 1}
	return C(2 * n, n) - C(2 * n, n + 1)

def Catalan_3(n): # C_n = C_{2n + 1}^n / (2n + 1)
	return C(2 * n + 1, n) // (2 * n + 1)

def Catalan_4(n): # C_0 = 1, C_n = 2(2n - 1)/(n + 1) * C_{n-1}
	if n == 0:
		return 1
	else:
		return 2 * (2 * n - 1) * Catalan_4(n - 1) // (n + 1)
'''
def Catalan_5(n): # C_0 = 1, C_n = \sum_{i=1}^n C_{i-1}C_{n-i}
	if n == 0:
		return 1
	else:
		ans = 0
		for i in range(n + 1):
			ans += Catalan_5(i - 1) * Catalan_5(n - i)
		return ans

def Catalan_5(n): # C_0 = 1, C_n = \sum_{i=1}^n C_{i-1}C_{n-i}
	if n == 0:
		return 1
	else:
		arr = [0] * (n + 2)
		for i in range(n + 1):
			for j in range(i + 1):
				arr[i] += Catalan_5(j - 1) * Catalan_5(i - j)
	return arr[n]
[Previous line repeated 996 more times]
RecursionError: maximum recursion depth exceeded
'''
n, k = map(int, input().split())
print(f'P_{n} = {P(n)}')
print(f'A_{n}^{k} = {A(n, k)}')
print(f'C_{n}^{k} = {C(n, k)}')
print(f'C_{n} = {Catalan(n)} = {Catalan_1(n)} = {Catalan_2(n)} = {Catalan_3(n)} = {Catalan_4(n)}')