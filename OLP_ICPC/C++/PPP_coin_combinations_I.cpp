#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

int main() {
    int n, x; // tổng số đồng xu & tổng tiền mong muốn
    cin >> n >> x;
    vector<int> coin_sack(n);
    for (int i = 0; i < n; ++i) cin >> coin_sack[i];
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;  // 1 cách tạo 0 cent
    for (int i = 1; i <= x; ++i) // tính trước số cách tổ hợp với DP
        for (int coin : coin_sack)
            if (i - coin >= 0) dp[i] = (dp[i] + dp[i - coin]) % mod;
    cout << dp[x];
}