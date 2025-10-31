#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1), c(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int total = 0;
        vector<int> dp(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            dp[i] = c[i];
            total += c[i];
        }
        // dp[i] : tổng trọng số lớn nhất của dãy con ko giảm kết thúc tại i

        for (int i = 1; i <= n; i++) {
            int best = 0;
            for (int j = 1; j < i; j++) {
                if (a[i] >= a[j]) {
                    best = max(best, dp[j]);
                }
            }
            dp[i] = c[i] + best;
        }
        int ans = *max_element(dp.begin() + 1, dp.end());
        ans = total - ans;
        cout << ans << endl;
    }
}
