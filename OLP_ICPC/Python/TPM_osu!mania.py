import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    a = []
    for _ in range(n):
        line = input().strip()
        a.append(line)
    a.reverse()
    for i in a:
        for j in range(5):
            if i[j] == '#':
                print(j+1,end=' ')
                break
    print()