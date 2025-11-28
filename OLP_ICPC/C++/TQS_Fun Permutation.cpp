#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) cin >> a[i];
        for (ll i = 0; i < n; ++i) {
            cout << n - a[i] + 1 << " ";
        }
        cout << "\n";
    }
}
