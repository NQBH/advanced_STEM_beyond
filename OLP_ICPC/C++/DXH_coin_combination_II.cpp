#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

void solve_vector(ll N, ll X, vector<ll> coins) {
    vector<ll> dp(X + 1, 0);
    dp[0] = 1;

    for (auto c : coins) {
        for (ll i = c; i <= X; ++i) {
            dp[i] += dp[i - c];
            dp[i] %= MOD;
        }
    }

    cout << dp[X] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, X; //Số loại đồng xu và tổng tiền
    cin >> N >> X;

    vector<ll> coins(N); //mảng chứa mệnh giá của từng loại đồng xu
    for (ll i = 0; i < N; ++i) {
        cin >> coins[i];
    }

    solve_vector(N, X, coins);
    return 0;
}