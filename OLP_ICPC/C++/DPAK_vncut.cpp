#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dp[i][j] = 1;
            } else {
                for (int k = 1; k <= i / 2; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
                }
                for (int k = 1; k <= j / 2; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
                }
            }
        }
    }

    cout << dp[m][n];
}