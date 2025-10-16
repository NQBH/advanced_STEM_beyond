#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll q; cin >> q;
    while (q--) {
        ll n; cin >> n;
        vector<ll> a(n), odd;
        ll even = 0;
        for (auto &i : a) {
            cin >> i;
            if (i & 1) odd.push_back(i);
            else even += i;
        }
        ll len = odd.size();
        if (!len) cout << 0 << "\n";
        else {
            sort(odd.begin(), odd.end(), greater<ll>());
            if (len & 1) {
                for (ll i = 0; i <= len / 2 ; ++i) {
                    even += odd[i];
                }
            }
            else {
                for (ll i = 0; i <= len / 2 - 1 ; ++i) {
                    even += odd[i];
                }
            }
            cout << even << "\n";
        }
    }
}
