#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        bool ans = true;
        for (ll i = 1; i <= n; ++i) {
            if (max(n - i, i - 1) * 2 >= a[i]) {
                ans = false;
                break;
            }
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}
