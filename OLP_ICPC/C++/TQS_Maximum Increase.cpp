#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i<n; i++) cin >> a[i];
    ll i = 0;
    ll ans = 1;
    ll kq = 1;
    while (i<n-1)
    {
        if (a[i]<a[i+1])
        {
            ans++;
            i++;
        }
        else
        {
            kq = max(kq,ans);
            ans = 1;
            i++;
        }
    }
    kq = max(kq,ans);
    cout << kq;
}
