#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
int n, m;
int a[100001];
ll dp[100001][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; ++i)
        if (i == 0) {
            if (a[i] == 0)
                for (int j = 1; j <= m; ++j) dp[i][j] = 1;
            else dp[i][a[i]] = 1;
        }
        else {
            if (a[i] == 0) {
                for (int j = 1; j <= m; ++j)
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
            }
            else dp[i][a[i]] = (dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1]) % MOD;
        }

    ll ans = 0;
    for (int i = 1; i <= m; ++i)
        ans = (ans + dp[n - 1][i]) % MOD;
    cout << ans << endl;

    return 0;
}