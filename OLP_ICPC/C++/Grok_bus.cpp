#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct Event {
    ll pos;
    ll len;          // ti-si for bus,  person index for query
    int type;        // 0 = bus, 1 = query
    int idx;
    bool operator<(const Event& ot) const {
        if (pos != ot.pos) return pos < ot.pos;
        return type < ot.type;   // bus before query
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, L;
    int x, y;
    if (!(cin >> n >> m >> L >> x >> y)) return 0;

    map<ll, ll> best;                     // si -> max ti
    for (ll i = 0; i < n; ++i) {
        ll s, t; cin >> s >> t;
        best[s] = max(best.count(s) ? best[s] : 0, t);
    }

    vector<ll> pos(m);
    for (int i = 0; i < m; ++i) cin >> pos[i];

    vector<Event> ev;
    ev.reserve(best.size() + m);
    for (auto [s, t] : best) {
        ev.push_back({s, t - s, 0, -1});
    }
    for (int i = 0; i < m; ++i) {
        ev.push_back({pos[i], (ll)i, 1, i});
    }
    sort(ev.begin(), ev.end());

    vector<ld> ans(m);
    ll maxLen = 0;
    ld B = (ld)y / (x + y);               // y/(x+y)

    for (auto &e : ev) {
        if (e.type == 0) {                // bus
            maxLen = max(maxLen, e.len);
        } else {                          // person
            int i = e.idx;
            ll p = pos[i];
            ld walk = (L - p) * 1.0L / y;

            ld useBus = 1e100L;
            if (maxLen > 0) {
                ld r = p + maxLen * B;
                r = min(r, (ld)L);
                ld ride = (r - p) / x;
                ld remain = (L - r) / y;
                useBus = ride + remain;
            }
            ans[i] = min(walk, useBus);
        }
    }

    cout << fixed << setprecision(15);
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}