#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k; cin >> n >> k;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) cin >> a[i][j];
    }
    vector<ll> ans(k, 0);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

    for (ll c = 0; c < k; ++c) {
        char CHAR = c + 'A';
        dp.resize(n + 1, vector<ll>(n + 1, 0)); // reset value
        for (ll i = 1; i <= n; ++i)
            for (ll j = 1; j <= n; ++j)
                ans[c] += dp[i][j] = (a[i][j] == CHAR ? min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1 : 0);
    }

    for (ll c = 0; c < k; ++c) cout << ans[c] << '\n';
}