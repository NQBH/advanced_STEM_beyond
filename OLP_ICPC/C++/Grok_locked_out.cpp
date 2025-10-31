#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> cnt(n + 2, 0);
        for (int x : a) cnt[x]++;

        vector<int> dp(n + 2, 0);
        dp[0] = 0;
        dp[1] = cnt[1];
        for (int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i]);
        }

        int kept = dp[n];
        cout << n - kept << "\n";
    }
    return 0;
}
