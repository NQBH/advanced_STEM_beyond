#include <bits/stdc++.h>
using namespace std;
#define ll int
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n;
        vector<ll> r(n);
        for (ll i = 0; i < n; ++i) cin >> r[i];
        cin >> m;
        vector<ll> b(m);
        for (ll i = 0; i < m; ++i) {
            cin >> b[i];
        }
        ll tmax1, tmax2, max1, max2;
        tmax1 = r[0];
        tmax2 = b[0];
        max1 = max(0, r[0]);
        max2 = max(0, b[0]);
        for (ll i = 1; i < n; ++i) {
            tmax1 += r[i];
            max1 = max(max1, tmax1);
        }
        for (ll i = 1; i < m; ++i) {
            tmax2 += b[i];
            max2 = max(max2, tmax2);
        }
        cout << max1 + max2 << "\n";
    }
}
