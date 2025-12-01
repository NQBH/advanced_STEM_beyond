#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll kadane(const vector<ll>& a) {
    ll best = LLONG_MIN, cur = 0;
    for (ll x : a) {
        cur = max(x, cur + x);
        best = max(best, cur);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        ll base = kadane(a);

        ll gain = 0, maxGain = LLONG_MIN, minGain = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            gain += b[i];
            maxGain = max(maxGain, gain);
            minGain = min(minGain, gain);
        }

        ll delta = maxGain - minGain;

        ll ans;
        if (k % 2 == 1) {
            // Alice ends
            ans = base + (k / 2) * delta;
        } else {
            // Bob ends
            ans = base + (k / 2 - 1) * delta + max(0LL, delta);
        }

        cout << ans << "\n";
    }
    return 0;
}
// WA