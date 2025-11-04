tt = int(input())
for t in range(tt):
    n = int(input())
    grumpiness = list(map(int, input().split()))
    grumpiness.sort()
    tot = 0
    for i in range(n - 1, -1, -2):
        tot += grumpiness[i]
    print(tot)