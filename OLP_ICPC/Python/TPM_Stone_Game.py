import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    vi_tri_big = a.index(max(a)) + 1
    vi_tri_nho = a.index(min(a)) + 1
    nho = min(vi_tri_big, vi_tri_nho)
    to = max(vi_tri_big, vi_tri_nho)
    TH1 = to
    TH2 = n - nho + 1
    TH3 = nho + (n - to + 1)
    print(min(TH1, TH2, TH3))