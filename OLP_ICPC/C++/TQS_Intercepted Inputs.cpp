#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll a; cin >> a;
        vector<ll> b(a);
        for (auto &i : b) cin >> i;
        ll n = 0, m = 0;
        ll s = a - 2;
        sort(b.begin(), b.end());
        for (ll i = 0; i < a - 1; ++i) {
            if (s % b[i] == 0) {
                auto k = lower_bound(b.begin(), b.end(), (s / b[i]));
                if (k == b.end()) continue;
                if (s / b[i] == *k) {
                    n = b[i];
                    m = (*k);
                    break;
                }
            }
        }
        cout << n << " " << m << "\n";
    }
}
