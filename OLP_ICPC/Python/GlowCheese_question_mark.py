t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    print(sum(min(n, s.count(c)) for c in "ABCD"))