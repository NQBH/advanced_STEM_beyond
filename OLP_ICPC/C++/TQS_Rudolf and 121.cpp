#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        bool ans = true;
        for (ll i = 0; i < n; ++i) cin >> a[i];
        for (ll i = 0; i < n - 2; ++i) {
            if (a[i] < 0) {
                ans = false;
                break;
            }
            a[i + 1] -= 2 * a[i];
            a[i + 2] -= a[i];
            a[i] = 0;
        }
        if (ans) {
            if (a[n - 1] != 0 or a[n - 2] != 0) cout << "NO\n";
            else cout << "YES\n";
        }
        else cout << "NO\n";
    }
}
