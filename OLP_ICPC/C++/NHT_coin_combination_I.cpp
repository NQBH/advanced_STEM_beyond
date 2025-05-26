#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1000000007;
int n, x;
ll dp[1000005], coins[1000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for(int i=0;i<n;++i) cin>>coins[i];

    //sort(coins, coins + n);
    dp[0] = 1;
    for(int i=1;i<=x;++i)
        for(int j=0;j<n;++j)
        {
            if (coins[j] > i) continue;
            dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
        }
    cout << dp[x] << '\n';

    return 0;
}