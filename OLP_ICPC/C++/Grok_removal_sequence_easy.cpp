#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1000000000000LL;          // 10^12
vector<ll> a;                            // distinct y-values

/* safe lcm = cur / gcd(cur,next) * next */
ll safe_lcm(ll cur, ll nxt, ll limit) {
    ll g = __gcd(cur, nxt);
    ll part = cur / g;
    if (nxt > limit / part) return limit + 1;   // overflow -> treat as > limit
    return part * nxt;
}

/* inclusion-exclusion DFS */
ll dfs(int idx, ll cur, ll lim) {
    if (idx == (int)a.size()) return lim / cur;

    ll res = 0;
    // skip a[idx]
    res += dfs(idx + 1, cur, lim);
    // take a[idx]
    ll lcm = safe_lcm(cur, a[idx], lim);
    if (lcm <= lim) res -= dfs(idx + 1, lcm, lim);
    return res;
}

/* numbers <= x that are not divisible by any y */
ll survivors(ll x) {
    if (x <= 0) return 0;
    return dfs(0, 1LL, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int x;
        cin >> x;                     // read x

        vector<ll> ys(x);
        for (int i = 0; i < x; ++i)    // read the x values of y
            cin >> ys[i];

        ll k;
        cin >> k;                     // finally read k

        /* keep only distinct y's */
        set<ll> uniq(ys.begin(), ys.end());
        a.assign(uniq.begin(), uniq.end());

        /* binary search for the smallest number with >=k survivors */
        ll lo = 1, hi = INF;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (survivors(mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        ll ans = -1;
        if (lo <= INF && survivors(lo) >= k) ans = lo;
        cout << ans << '\n';
    }
    return 0;
}
// CE