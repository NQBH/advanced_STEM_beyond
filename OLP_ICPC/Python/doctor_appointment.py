T = int(input())
t = int(input())
while T != 0:
	T -= 1
	n, x = map(int, input().split())
	if x >= t: ans = 0
	else:
		ans = (n - 1) * (t - x)
	print(ans)