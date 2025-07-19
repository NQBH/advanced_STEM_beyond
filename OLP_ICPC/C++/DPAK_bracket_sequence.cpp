#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(char c, char v) {
    return ((c == '(' && v == ')') || (c == '[' && v == ']'));
}

int main() {
    string s;
    while (cin >> s) {
        ll n = s.size();
        if (n == 0) {
            printf("\n");
            continue;
        }
        s = " " + s; // 0-based indexing --> 1-based indexing
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, INT_MAX)), path(n + 1, vector<ll>(n + 1));
        for (ll i = 1; i <= n; ++i) dp[i][i] = 1;
        for (ll r = 1; r <= n; ++r)
            for (ll l = r - 1; l >= 1; --l)
                if (check(s[l], s[r])) {
                    if (l == r - 1) dp[l][r] = 0;
                    else {
                        dp[l][r] = dp[l + 1][r - 1];
                        path[l][r] = -1;
                        for (ll k = l; k < r; ++k)
                            if (dp[l][r] > dp[l][k] + dp[k + 1][r]) {
                                dp[l][r] = dp[l][k] + dp[k + 1][r];
                                path[l][r] = k;
                            }
                    }
                }
                else dp[l][r] = min(dp[l + 1][r] + 1, dp[l][r - 1] + 1);
        cout << dp[1][n] << '\n';
        for (ll i = 1; i <= n; ++i)
            for (ll j = 1; j <= n; ++j)
                cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
    }


}