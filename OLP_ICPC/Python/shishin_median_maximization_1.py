t = int(input())
for test in range(t):
    n, s = map(int, input().split())
    L = 0
    R = 10**10
    while R - L > 1:
        M = (L + R) // 2
        m = n // 2 + 1
        if m * M <= s:
            L = M
        else:
            R = M
    print(L)