#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;
int t, n;
ll dp[1000001][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1][1] = dp[1][2] = 1;
    for(int i=2;i<=1e6;++i){
        dp[i][1] = (dp[i-1][1]*4 + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2]*2) % MOD;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = (dp[n][1] + dp[n][2]) % MOD;
        cout << ans << endl;
    }
    
    return 0;
}

//                                      _  _
// dp[i][1] = hàng cuối tách khối rời  | || |
//                                   _ _
// dp[i][2] = hàng cuối khối ghép   |   |
    
//              _  _    _  _    _  _    _  _     _ _
//  _  _       | || |  |_|| |  | ||_|  |_||_|   |_ _|
// | || | =>   | || |, | || |, | || |, | || |,  | | |
//              _ _    _ _    _ _ 
//  _ _        |   |  |_|_|  |_ _|
// |   |  =>   |   |, |   |, |   |