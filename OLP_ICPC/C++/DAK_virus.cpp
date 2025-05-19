#include <bits/stdc++.h>
#include <complex>
using namespace std;

const int mod =1e9+7;
int t;
int n,k;
/*
flashback
*/
void solve()
{
    cin >> n >> k;
    int f[100100];
    f[0]=n;
    f[1]=2*n;
    f[2]=5*n;
    for (int i=3;i<=k;i++)
    {
            f[i]=f[i-1]*3%mod-f[i-2];
    }
    cout << f[k] << " ";
}
int main() {
    cin >> t;
    while (t--)
        solve();
    return 0;
}