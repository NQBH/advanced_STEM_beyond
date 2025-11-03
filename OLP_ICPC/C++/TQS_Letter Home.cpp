#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n, s; cin >> n >> s;
        ll a[n];
        for (ll i = 0; i < n; ++i) cin >> a[i];
        if (s >= a[n - 1] or s <= a[0]) {
            cout << max(abs(s - a[n - 1]), abs(s - a[0])) << "\n";
            continue;
        }
        cout << min(abs(s - a[n - 1]), abs(s - a[0])) + a[n - 1] - a[0] << "\n";
    }
}
