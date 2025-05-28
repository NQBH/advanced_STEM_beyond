#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

/*
Phan tich:
    sum = n
    ===> min = 1
    dp[i] : so cach tung xuc xac tong = i
    dp[0] = dp[1] = 1;
*/

int main(){
    int n; cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                (dp[i] += dp[i - j]) %= mod;
            }
        }
    }
    cout << dp[n];
}