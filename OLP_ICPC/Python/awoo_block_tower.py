for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    x = a[0]
    a = sorted(a[1:])
    for y in a:
        if y > x:
            x += (y - x + 1) // 2
    print(x)