def solve():
	n, q = map(int, input().split())
	s = input()
	a = list(map(int, input().split()))
	A = s.count('A')
	B = s.count('B')
	last = s[0]
	seq = []
	cur = 1
	for i in range(1, n):
		if (s[i] == last): cur += 1
		else:
			seq.append([last, cur])
			cur = 1
			last = s[i]
	if (cur != 0): seq.append([last, cur])
	if (B == 0):
		for i in a: print(i)
	else:
		for i in range(q):
			ans = 0
			while (a[i] > 0):
				for j in seq:
					if (a[i] == 0): break
					if (j[0] == 'A'):
						mn = min(j[1], a[i])
						ans += mn
						a[i] -= mn
					else:
						if a[i] == 0: break
						x = a[i]
						p = 0
						while (x):
							x //= 2
							p += 1
						mn = min(p, j[1])
						ans += mn
						a[i] //= (2 ** mn)
			print(ans)

for _ in range(int(input())):
    solve()