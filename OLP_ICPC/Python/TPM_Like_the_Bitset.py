t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    s = input()
    z = len(set(s))
    dem1 = 0
    dem0 = s.count('1')
    t = 0
    if z == 1 and s[0] == '0':
        print('YES')
        for i in range(1,n+1):
            print(i,end=' ')
        print()
    elif (z == 1 and s[0] == '1') or (k == 1 and z == 2):
        print('NO')
    elif dem0 < k: 
        print('YES')
        for i in range(n):
            if s[i] == '0':
                dem0 += 1
                print(dem0,end=' ')
            else:
                dem1 += 1
                print(dem1,end=' ')
        print()
    else:
        a = [0] * n 
        for i in range(n):
            if s[i] == '1':
                if s[i:i+(k%n)].count('1') >= k:
                    print('NO')
                    t = 1
                    break
                else:
                    dem1 += 1
                    a[i] = str(dem1)
            else: 
                dem0 += 1
                a[i] = str(dem0)
        if t == 0:
            print('YES')
            print(' '.join(a))