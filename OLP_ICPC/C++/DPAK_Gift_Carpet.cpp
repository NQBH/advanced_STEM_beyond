#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const string pattern = " vika";
const int patternLength = 4;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n,m; cin >> n >> m;
        vector<vector<char>> a(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<bool>> dp(m + 1, vector<bool>(5, false));
        // dp[col][i] : co the ghep duoc pattern[1..i] sau khi da xet den cot col hay chua?
        dp[0][0] = true;
        
        for (int col = 1; col <= m; col++) {

            for (int i = 0; i <= patternLength; i++) {
                dp[col][i] = dp[col - 1][i];
            }

            for (int i = 1; i <= patternLength; i++) {
                bool found = false;
                for (int row = 1; row <= n; row++) {
                    if (a[row][col] == pattern[i]) {
                        found = true;
                        break;
                    }
                }
                if (found) {
                    dp[col][i] = dp[col - 1][i - 1];
                }
            }
        }

        cout << (dp[m][patternLength] ? "YES" : "NO") << endl;
    }
    return 0;
}