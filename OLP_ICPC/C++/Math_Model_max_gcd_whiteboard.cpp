#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    vector<int>a(n), mp(n + 1), p(n + 1);
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
    }
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + mp[i];
    }
    int ans = 1;
    for (int g = 1; g <= n; g++) {
        int t = min(n, 4 * g - 1);
        int good = n - p[t];
        good += mp[g];
        if (2 * g <= n)good += mp[2 * g];
        if (3 * g <= n)good += mp[3 * g];
        if (good >= n - k)ans = g;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--)solve();
}