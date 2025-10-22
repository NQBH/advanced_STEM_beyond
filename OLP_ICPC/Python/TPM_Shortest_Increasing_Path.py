t = int(input())
for _ in range(t):
    x,y = map(int, input().split())
    if (x < y):
        print(2)
    elif (x > y) and (x-1 > y) and (y > 1):
        print(3)
    else:
        print(-1)