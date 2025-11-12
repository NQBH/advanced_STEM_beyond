def solve():
	n = int(input())
	s1 = input()
	s2 = input()
	bad = False
	for i in range(n):
		bad |= s1[i] == '1' and s2[i] == '1'
	if bad:
		print('NO')
	else:
		print('YES')

t = int(input())
for i in range(t):
	solve()