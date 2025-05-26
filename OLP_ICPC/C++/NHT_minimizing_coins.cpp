#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;
int n, x;
ll dp[1000005], coins[1000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    for(int i=0;i<n;++i) cin>>coins[i];

    for(int i=0;i<=x;++i) dp[i] = INF;
    //sort(coins, coins + n);
    dp[0] = 0;
    for(int i=1;i<=x;++i)
        for(int j=0;j<n;++j)
            {
                if(coins[j] > i || dp[i - coins[j]] == INF) continue;
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
    if(dp[x] == INF) cout << -1 << '\n';
    else cout << dp[x] << '\n';

    return 0;
}