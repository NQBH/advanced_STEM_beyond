#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s;
    t = " " + t;
    // dp[i][j] : so luong min operation thuc hien s[1..i] va t[1..j]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, mod));

    // min ope : do dai chuoi con lai
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({dp[i - 1][j], // xoa
                                dp[i][j - 1], // chen
                                dp[i - 1][j - 1]
                               }) // replace
                           + 1;
            }
        }
    }
    cout << dp[n][m];
}