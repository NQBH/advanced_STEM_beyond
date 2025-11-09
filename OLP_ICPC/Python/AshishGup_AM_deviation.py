t=int(input())
for i in range(t):
    a,b,c=[int(x) for x in input().split()]
    print(0 if ((a+b+c)%3 == 0) else 1)