t = int(input())
for _ in range(t):
    a,b,c = map(int, input().split())
    if ((abs(b - a) / 2) % c == 0):
        print(int(((abs(b - a) / 2) // c )))
    else:
        total = 1 + ((abs(a - b) / 2) / c)
        print(int(total))