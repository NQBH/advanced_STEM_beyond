#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k, ans = 0;
        cin >> n >> k;
        vector<ll> q(n), r(n);
        for (auto &x : q) cin >> x;
        for (auto &x : r) cin >> x;
        map<ll, ll> fq, fr;
        for (ll x : q) ++fq[x];
        for (ll x : r) ++fr[x];
        vector<ll> uq;
        for (auto &p : fq) uq.push_back(p.first);
        sort(uq.begin(), uq.end());
        vector<pair<ll, ll>> R;
        for (auto &p : fr) R.push_back({p.first, p.second});
        sort(R.begin(), R.end());
        int i = 0;
        for (ll qv : uq) {
            ll limit = (k - qv) / (qv + 1);
            if (limit < 0) continue;
            ll need = fq[qv];
            while (need > 0 && i < R.size()) {
                if (R[i].first > limit) break;
                ll take = min(need, R[i].second);
                ans += take;
                need -= take;
                R[i].second -= take;
                if (R[i].second == 0) ++i;
            }
        }
        cout << ans << "\n";
    }
}
