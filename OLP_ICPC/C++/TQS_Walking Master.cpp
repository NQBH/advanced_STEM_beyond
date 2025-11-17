#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d < b) {
            cout << -1 << "\n";
            continue;
        }
        if (d - b < c - a) {
            cout << -1 << "\n";
        }
        else {
            ll ans = d - b;
            a += d - b;
            ans += a - c;
            cout << ans << "\n";
        }
    }
}
