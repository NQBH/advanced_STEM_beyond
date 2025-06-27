#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];
    vector<long long> res(k, 0);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (char c = 'A'; c < 'A' + k; ++c) {
        for (int i = 0; i < n; ++i)
            fill(dp[i].begin(), dp[i].end(), 0);
        long long d = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == c) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    d += dp[i][j];
                }
            }
        }
        res[c - 'A'] = d;
    }
    for (int i = 0; i < k; ++i) cout << res[i] << "\n";
    return 0;
}