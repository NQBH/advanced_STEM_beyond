#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

bool check(char c, char v) {
    return ((c == '(' && v == ')') || (c == '[' && v == ']'));
}

signed main() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }

    for (int r = 1; r <= n; r++) {
        for (int l = r - 1; l >= 1; l--) {
            if (check(s[l], s[r])) {
                if (l == r - 1) {
                    dp[l][r] = 0;
                }
                else {
                    dp[l][r] = dp[l + 1][r - 1];
                    for (int k = l; k < r; k++) {
                        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                    }
                }
            }
            else {
                dp[l][r] = min(dp[l + 1][r] + 1, dp[l][r - 1] + 1);
            }
        }
    }
    cout << dp[1][n] << endl;
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "dp[" << i << "]["<<j<<"] = " << dp[i][j] << endl;
        }
    }
    */
}