#include <bits/stdc++.h>
using namespace std;
int n,q,t;
int a[100001],ma[100001];
long long f[100001],g[100001];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
}
void solve()
{
    ma[n]=a[n];
    f[n]=0;
    g[n]=0;
    for (int i=n-1;i>=1;i--)
    {
        ma[i]=max(a[i],ma[i+1]);
        f[i]=ma[i]-a[i];
        g[i]=f[i]+g[i+1];
    }
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        cin>>t;
        cout<<g[t]<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("vni.inp","r",stdin);
    //freopen("vni.out","w",stdout);
    input();
    solve();
}