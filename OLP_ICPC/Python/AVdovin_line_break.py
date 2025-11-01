def solve():
    n, m = [int(i) for i in input().split()]
    ans = 0
    for i in range(n):
    	l = input()
    	if len(l) <= m:
    		m -= len(l)
    		ans += 1
    	else:
    		for i in range(i + 1, n):
    			input()
    		break
    print(ans)

t = int(input())
for i in range(t):
    solve()