#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) cin >> a[i];
        vector<ll> c(n + 1);
        vector<ll> b(n);
        c[0] = 0;
        for (ll i = 1; i <= n; ++i) c[i] = c[i - 1] + a[n - i];
        b[0] = a[0];
        for (ll i = 1; i < n; ++i) {
            b[i] = max(a[i], b[i - 1]);
        }
        for (ll i = 0; i < n; ++i) {
            cout << c[i] + b[n - 1 - i] << " ";
        }
        cout << "\n";
    }
}
