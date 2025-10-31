t = int(input())
for _ in range(t):
    n,q = map(int, input().split())
    s = input()
    a = list(map(int, input().split()))
    if ("B" not in s):
        for x in a:
            print(x)
    else:
        for x in a:
            dem = 0
            while x > 0:
                for i in range(len(s)):
                    dem += 1
                    if s[i] == 'A':
                        x -= 1
                    else:
                        x //= 2
                    if x <= 0:
                        break
            print(dem)