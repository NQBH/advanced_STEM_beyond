t = int(input())
for i in range(t):
	n = int(input())
	s = list(input().split())
    s = "".join(s)
    if "101" in s:
        print('NO')
    else:
        print('YES')