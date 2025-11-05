#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while (t--) {
        ll b, c; cin >> b >> c;
        map<ll, ll> a;
        ll bi, ci;
        while (c--) {
            cin >> bi >> ci;
            a[bi] += ci;
        }
        multiset<ll, greater<ll>> ans;
        for (auto it = a.begin() ; it != a.end() ; ++it) {
            ans.insert((*it).second);
        }
        ll kq = 0;
        for (ll i = 0; i < b && !ans.empty(); ++i) {
            kq += *ans.begin();
            ans.erase(ans.begin());
        }
        cout << kq << "\n";
    }
}
