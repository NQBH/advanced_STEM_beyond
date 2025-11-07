#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll C(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    ll res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}
int main()
{
    ll n; cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    vector<ll> c(n, 0), h(n, 0);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> a[i][j];
            h[i] += (a[i][j] == 'C');
            c[j] += (a[i][j] == 'C' ? 1 : 0);
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans = ans + C(h[i], 2) + C(c[i], 2);
    }
    cout << ans;
}
