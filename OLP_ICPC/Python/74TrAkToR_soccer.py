t = int(input())
for T in range(t):
	la, lb = map(int, input().split())
	ra, rb = map(int, input().split())
	if la > lb:
		la, lb, ra, rb = lb, la, rb, ra
	if la < lb and rb < ra:
		print("NO")
	else:
		print("YES")