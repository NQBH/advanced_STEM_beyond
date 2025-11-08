for _ in range(int(input())):
	n, k, x = map(int, input().split())
	if x != 1:
		print("YES")
		print(n)
		print(*([1] * n))
	elif k == 1 or (k == 2 and n % 2 == 1):
		print("NO")
	else:
		print("YES")
		print(n // 2)
		print(*([3 if n % 2 == 1 else 2] + [2] * (n // 2 - 1)))