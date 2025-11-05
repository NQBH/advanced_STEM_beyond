#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for (auto &i : a) cin >> i;
        sort(a.begin(), a.end(), greater<ll>());
        ll s = 0;
        for (ll i = 0; i < n; ++i) {
            if (s + a[i] <= k) s += a[i];
            else break;
        }
        cout << k - s << "\n";
    }
}
