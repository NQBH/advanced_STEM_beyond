/*
    VTP - IMO 2007 P1
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long r) {
    return uniform_int_distribution<long long> (0, r - 1)(rng);
}
long long Rand(long long l, long long r) {
    return uniform_int_distribution<long long> (l, r)(rng);
}

void solve() {
    int n; cin >> n;
    vector<double> a(n + 1, 0), d(n + 1, 0), max_head(n + 1), min_tail(n + 1), x(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    max_head[1] = a[1];
    min_tail[n] = a[n];
    for (int i = 2; i <= n; ++i) max_head[i] = max(max_head[i - 1], a[i]);
    for (int i = n - 1; i >= 1; --i) min_tail[i] = min(min_tail[i + 1], a[i]);
    // for(int i = 1; i <= n; ++i) cout << max_head[i] << " ";
    // cout << '\n';
    // for(int i = 1; i <= n; ++i) cout << min_tail[i] << " ";
    // cout << '\n';

    for (int i = 1; i <= n; ++i) d[i] = max_head[i] - min_tail[i];
    double d_max = *max_element(d.begin() + 1, d.end());
    cout << "d/2 = " << d_max / 2 << '\n';

    double a_min = min_tail[1];
    // cout << "a_min: " << a_min << '\n';
    int delta;
    for (int i = 1; i <= n; ++i)
        if (a[i] - a_min > d_max) {
            delta = i;
            break;
        }
    
    // cout << "delta: " << delta << '\n';

    for (int i = 1; i <= delta - 1; ++i) x[i] = d_max / 2 + a_min;
    for (int i = delta; i <= n; ++i) x[i] = d_max / 2 + min_tail[i];
    for (int i = 1; i <= n; ++i) cout << x[i] << " ";
    cout << '\n';

    double max_abs = -1e9;
    for (int i = 1; i <= n; ++i) max_abs = max(max_abs, abs(x[i] - a[i]));
    cout << "max|xi - ai| = " << max_abs << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--)
        solve();

    return 0;
}