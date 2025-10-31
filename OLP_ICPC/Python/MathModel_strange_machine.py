def solve():
	n, q = map(int, input().split())
	s = input().strip()
	a = list(map(int, input().split()))
	A, B = s.count('A'), s.count('B')
	for i in range(q):
		if (B == 0):
			print(a[i])
		else:
			ans = 0
			while (a[i]):
				for j in s:
					if (a[i] == 0): break
					ans += 1
					if (j == 'A'): a[i] = -1
					else: a[i] //= 2
			print(ans)

for _ in range(int(input())):
	solve()