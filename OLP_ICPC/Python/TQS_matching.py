t = int(input())
while(t!=0):
    n=input()
    s=n.count('?')
    if (n[0]=='0'):
        print(0)
    elif (s==0):
        print(1)
    else:
        ans=1
        if(n[0]=='?'):
            ans*=9
            s-=1
        ans= ans * (10**s)
        print(ans)
    t-=1
    