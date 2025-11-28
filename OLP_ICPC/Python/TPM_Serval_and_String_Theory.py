import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()
    a = s[::-1]
    if len(set(s)) == 1:
        print("NO")
        continue
    if s < a:
        print("YES")
    else:
        if k > 0:
            print("YES")
        else:
            print("NO")