#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        ll ans = 0;
        ll k = 1;
        for (ll i = 0; i < n; ++i, k = -k) {
            ll a; cin >> a;
            ans += a * k;
        }
        cout << ans << "\n";
    }
}
