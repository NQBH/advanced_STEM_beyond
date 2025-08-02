#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

// --- Bottom-up dùng mảng thường ---
ll solve_array(ll N, ll X, vector<ll>& coins) {
    ll dp[X + 1] = {}; // Khởi tạo tất cả các phần tử bằng 0
    dp[0] = 1;         // Có 1 cách để tạo ra tổng 0 (không chọn đồng xu nào)

    for (ll i = 1; i <= X; ++i) {
        for (ll j = 0; j < N; ++j) {
            if (coins[j] <= i)
                dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
        }
    }
    return dp[X]; // Trả về số cách để tạo ra tổng X
}

// --- Bottom-up dùng vector ---
ll solve_vector(ll N, ll X, vector<ll>& coins) {
    vector<ll> dp(X + 1, 0);
    dp[0] = 1; 

    // Duyệt qua từng tổng 'i' từ 1 đến X
    for (ll i = 1; i <= X; ++i) {
        for (ll c : coins) {
            if (c <= i)
                dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }
    return dp[X]; // Trả về số cách để tạo ra tổng X
}

// --- Top-down đệ quy với memo ---
ll solve_recursive(ll x, vector<ll>& coins, vector<ll>& memo) {
    if (x == 0) return 1; 
    if (x < 0) return 0;  
    if (memo[x] != -1) return memo[x]; 

    ll res = 0; // Biến 'res' để tích lũy số cách
    // Duyệt qua từng đồng xu 'c'
    for (ll c : coins) {
        res = (res + solve_recursive(x - c, coins, memo)) % MOD;
    }
    return memo[x] = res; // Lưu kết quả vào memo[x] và trả về
}

int main() {
    ll N = 3, X = 9;         // N: số lượng đồng xu, X: tổng cần đạt
    vector<ll> coins = {2, 3, 5}; // Các giá trị đồng xu có sẵn


    cout << "DP array: " << solve_array(N, X, coins) << "\n";

    cout << "DP vector: " << solve_vector(N, X, coins) << "\n";

    vector<ll> memo(X + 1, -1);
  
    cout << "Recursive memo: " << solve_recursive(X, coins, memo) << "\n";

    return 0; 
}