import sys
input = lambda: sys.stdin.readline().strip()

t = int(input())
outs = []
for _ in range(t):
	x, y, z = map(int, input().split())
	a = x | z
	b = x | y
	c = y | z
	outs.append('YES' if a & b == x and b & c == y and a & c == z else 'NO')
print('\n'.join(outs))