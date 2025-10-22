#include <bits/stdc++.h>
#define APC signed
#define int long long
using namespace std;

const int oo = 1e9;

APC main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int total = 1 << n;
    int ans = 0;
    for (int i = 1; i < total; i++) {
        if (__builtin_popcount(i) < 2) continue;
        int cnt = 0;
        int SUM = 0, MIN =  1e6 + 5, MAX = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                MIN = min(MIN, a[j]);
                MAX = max(MAX, a[j]);
                SUM += a[j];
                cnt++;
            }
            if (SUM > r) break;
        }
        int c = MIN - MAX; c -= 2 * c;
        if (cnt >= 2 && SUM >= l && SUM <= r && c >= x) ans++;
    }
    cout << ans;
}
