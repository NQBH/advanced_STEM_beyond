t = int(input())
for _ in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	lsum = rsum = 0
	for i in range(n//2):
		lsum += a[i]
	for i in range(n//2, n):
		rsum += a[i]
	print(lsum * rsum)