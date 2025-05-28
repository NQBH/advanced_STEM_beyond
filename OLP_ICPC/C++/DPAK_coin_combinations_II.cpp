#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    int n, x; 
    cin >> n >> x;
    vector<int> coins(n);
    vector<int> dp(1e6 + 1, 0);
    // dp[i] : so cach pb tao ra i
    for (int i = 0; i < n; i++) {
        cin >> coins[i]; // dp[coins[i]] = 1;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int cost = coins[i]; cost <= x; cost++) {
            (dp[cost] += dp[cost - coins[i]]) %= mod;
        }
    }
    cout << dp[x];
}