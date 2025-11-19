import sys
input = lambda: sys.stdin.readline().strip()
t = int(input())
for _ in range(t):
    n = int(input())
    s = list(map(int, input()))
    if (len(set(s)) == 1) or (s == sorted(s)):
        print(0)
    elif n == 2: print(1)
    else:
        dem = 0
        for i in range(s.index(1),n-1):
            if (s[i] + s[i+1] == 1):
                dem +=  1
        print(dem)



'''

if (s[i] == 0) and (s[0] != 0):
                dem += 1
                for j in range(i,n):
                    s[j] ^= 1
            elif (s[i] == 1) and (s[0] == 0) and (i < n -1) and (s[i + 1] != 1):
                dem += 1
                for j in range(i,n):
                    s[j] ^= 1
                    
                    '''