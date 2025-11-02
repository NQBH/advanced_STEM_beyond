t = int(input())
for i in range(t):
    n = int(input())
    a = input().split(" ")
    count = 0
    for i in range(0, n):
        add = 1
        for j in range(0, i):
            if a[i]==a[j]:
                add = 0
        count += add
    print(count)