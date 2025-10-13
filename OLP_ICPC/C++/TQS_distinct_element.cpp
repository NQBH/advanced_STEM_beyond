#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a, b(n);
        for (ll &i : b) cin >> i;
        ll k = 1;
        a.push_back(1);
        for (ll i = 1; i < n; ++i) {
            ll len = b[i] - b[i - 1];
            if (len == i + 1) a.push_back(++k);
            else {
                a.push_back(a[i - len]);
            }
        }
        for (auto &i : a) cout << i << " ";
        cout << "\n";
    }
}