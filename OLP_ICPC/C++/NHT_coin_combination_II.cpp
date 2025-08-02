#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1000000007;
int n, x;
ll dp[1000005], coins[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> coins[i];
    // sort(coins, coins + n);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = coins[i]; j <= x; ++j)
            dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
    cout << dp[x] << '\n';
}