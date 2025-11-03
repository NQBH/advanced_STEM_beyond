import sys
input = lambda: sys.stdin.readline().strip()
t=int(input())
for _ in range(t):
	n,j,k = map(int,input().split())
	a = list(map(int, input().split()))
	if k > 1 or max(a)==a[j-1]:
		print('YES')
	else: 
		print('NO')
