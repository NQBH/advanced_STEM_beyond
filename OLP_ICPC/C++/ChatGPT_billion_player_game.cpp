#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve_endpoint(vector<ll> d) {
    int n = d.size();
    sort(d.begin(), d.end());  // ascending

    vector<ll> pref(n+1), suf(n+1);
    pref[0] = 0;
    for (int i = 0; i < n; i++) pref[i+1] = pref[i] + d[i];
    suf[n] = 0;
    for (int i = n-1; i >= 0; i--) suf[i] = suf[i+1] + d[i];

    ll best = LLONG_MIN;

    for (int k = 0; k+1 <= n; k++) {
        ll sum_top_k = (k==0 ? 0 : suf[n-k]);
        ll sum_bot_k1 = pref[k+1];
        best = max(best, sum_top_k - sum_bot_k1);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll l, r;
        cin >> n >> l >> r;

        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        vector<ll> dl(n), dr(n);
        for (int i = 0; i < n; i++) {
            dl[i] = a[i] - l;
            dr[i] = a[i] - r;
        }

        ll best_l = solve_endpoint(dl);
        ll best_r = solve_endpoint(dr);

        ll ans = max({0LL, best_l, best_r});
        cout << ans << "\n";
    }
}
