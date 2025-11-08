T = int(input())
for _ in range(T) :
	l, r = map(int, input().split())
	print(((r + 1) // 2 - l // 2) // 2)