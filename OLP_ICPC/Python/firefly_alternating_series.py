import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

def solve():
    n = ii()
    if n == 1:
        return [0]
    ans = [-1, 3] * (n // 2)
    if n % 2:
        ans.append(-1)
    else:
        ans[-1] = 2
    return ans

for _ in range(ii()):
    print(*solve())