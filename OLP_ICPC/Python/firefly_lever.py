import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

def solve():
    n = ii()
    A = lii()
    B = lii()
    return sum(a - b for a, b in zip(A, B) if a > b) + 1

for _ in range(ii()):
    print(solve())