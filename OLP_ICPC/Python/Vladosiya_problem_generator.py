def solve():
    n, m = map(int, input().split())
    a = input()
    ans = 0
    for ch in range(ord('A'), ord('H')):
        ans += max(0, m - a.count(chr(ch)))
    print(ans)
    
    
for _ in range(int(input())):
    solve()