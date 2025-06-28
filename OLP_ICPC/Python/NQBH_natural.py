def is_natural(n):
	if n == 0: return 1
	else: return is_natural(n - 1)

n = int(input())
print(is_natural(n))