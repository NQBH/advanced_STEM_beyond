#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
int n;
ll dp[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dp[1] = 1;
    dp[2] = dp[1] + 1;
    dp[3] = dp[2] + dp[1] + 1;
    dp[4] = dp[3] + dp[2] + dp[1] + 1;
    dp[5] = dp[4] + dp[3] + dp[2] + dp[1] + 1;
    dp[6] = dp[5] + dp[4] + dp[3] + dp[2] + dp[1] + 1;
    for(int i=7; i<=n; ++i){
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % MOD;
    }
    cout << dp[n] << '\n';

    return 0;
}