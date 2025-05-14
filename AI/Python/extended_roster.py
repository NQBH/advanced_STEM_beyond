t = [] # 2D array of times t_{ij}
m, n = map(int, input().split())
for i in range(m):
	row = [int(x) for x in input().split()]
	t.append(row)
print(t)