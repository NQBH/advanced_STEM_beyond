#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1), t(m + 1);
    // dp[i][j] : do dai day con chung dai nhat khi s[1..i] va t[1..j]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int j = 1; j <= m; j++) {
        cin >> t[j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    // truy vet
    int i = n, j = m;
    vector<int> db;
    while (i >= 1 && j >= 1) {
        if (s[i] == t[j]) {
            db.push_back(s[i]);
            i--, j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    for (int i = db.size() - 1; i >= 0; i--) {
        cout << db[i] << " " ;
    }
}