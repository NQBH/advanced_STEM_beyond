tt = int(input())
for t in range(tt):
    n = int(input())
    gears = list(map(int, input().split()))
    valid = False
    for i in range(n):
        for j in range(i + 1, n):
            if gears[i] == gears[j]:
                valid = True
    if valid:
        print("YES")
    else:
        print("NO")