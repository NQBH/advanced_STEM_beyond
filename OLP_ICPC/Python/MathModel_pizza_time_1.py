from math import *

def solve():
	n = int(input())
	a, b, c = n // 3, n // 3, n // 3 + (n % 3)
	ans = 0
	while (n > 2):
		ans += n // 3
		n = n // 3 + (n % 3)
	print(ans)

for _ in range(int(input())):
	solve()