import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = input()
    dem = 0
    total = n.count('0')
    if total == 0: 
        print(len(n) - 1)
    else: 
        z = 0
        for i in range(len(n)-1,0,-1):
            if n[i] == '0':
                dem += 1
            else: 
                z = i
                break
        print(dem + len(n[:z]) - n[:z].count('0'))