# Source: Christoph D\"urr, Jill-J\^enn Vie. Competitive Programming in Python: 128 Algorithms to Develop Your Coding Skills. 2021

# gcd
def pgcd(a, b): # O(log a + log b)
	return a if b == 0 else pgcd(b, a % b)

# Bézout coefficients
def bezout(a, b): # O(log a + log b)
	if b == 0:
		return (1, 0)
	u, v = bezout(b, a % b)
	return (v, u - (a // b) * v)

def inv(a, p):
	return bezout(a, p)[0] % p

# binomial coefficients
def binom(n, k):
	prod = 1
	for i in range(k):
		prod = (prod * (n - i)) // (i + 1)
	return prod

def binom_modulo(n, k, p):
	prod = 1
	for i in range(k):
		prod = (prod * (n - i) * inv(i + 1, p)) % p
	return prod