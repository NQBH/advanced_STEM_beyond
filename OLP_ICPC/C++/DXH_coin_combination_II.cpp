#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

void solve_vector(ll n, ll x, vector<ll> coins) {
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (auto c : coins)
        for (ll i = c; i <= x; ++i) {
            dp[i] += dp[i - c];
            dp[i] %= MOD;
        }
    cout << dp[x] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x; // số loại đồng xu & tổng tiền
    cin >> n >> x;

    vector<ll> coins(n); //mảng chứa mệnh giá của từng loại đồng xu
    for (ll i = 0; i < n; ++i)  cin >> coins[i];
    solve_vector(n, x, coins);
    return 0;
}