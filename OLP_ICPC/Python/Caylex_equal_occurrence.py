def solve():
	n = int(input())
	ls = list(map(int, input().split()))
	a = [0] * n
	for x in ls:
		a[x - 1] += 1
	a = sorted(a)
	s = sum(a)
	ans = s
	for i in range(n):
		ans = min(ans, s - (n - i) * a[i])
	print(n - ans)
	return

t = int(input())
for _ in range(t):
	solve()