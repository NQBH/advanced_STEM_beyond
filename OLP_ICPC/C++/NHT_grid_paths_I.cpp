#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e3 + 3;

int n;
char a[maxn][maxn];
ll dp[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    
    if (a[1][1] != '*') dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (i == 1 && j == 1) continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            if (a[i][j] == '*') dp[i][j] = 0;
        }

    cout << dp[n][n] << "\n";
    return 0;
}
