t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    t = s[::-1]
    print(min(s, t + s))