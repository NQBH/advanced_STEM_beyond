def count_digit(x, k):
	if x == k == 0:
		return 1
	ans = 0
	while x:
		ans += (1 if x % 10 == k else 0)
		x //= 10
	return ans

t = int(input())
while t:
	t -= 1
	n, k = map(int, input().split())
	A = list(map(int, input().split()))
	ans = 0
	for a in A:
		ans += count_digit(a, k)
	print(ans)