#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// dp[i] : so dong xu it nhat tao ra i

int main(){
    int n, x; cin >> n  >> x;
    vector<int>coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, mod);
    dp[0] = 0; // ro rang 
    for (int cost = 1; cost <= x; cost++){
        for (int coin = 0; coin < n; coin++) {
            if (cost - coins[coin] >= 0) {
                // so cach it nhat khi giu nguyen hoac chon coins hien tai
                dp[cost] = min(dp[cost], dp[cost - coins[coin]] + 1);
            }
        }
    }
    cout << (dp[x] == mod ? -1 : dp[x]);
}