#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define el "\n";
#define elif else if
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pops pop_back
#define cYES cout << "YES" << "\n";
#define cNO cout << "NO" << "\n";
#define cYes cout << "Yes" << "\n";
#define cNo cout << "No" << "\n";
#define cel cout << "\n";
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

const int M = 1000000007;
// dp[i][w]: w: cost, i: item

SORAI {
    Sanic_speed
    int n, k;
    cin >> n >> k;
    int dp[n+1][k+1];
    fill_n(&dp[0][0], (n+1)*(k+1), 0);
    vector<pair<int,int>> bp(n+1);
    fre(i, 1, n) {cin >> bp[i].fi;}
    fre(i, 1, n) {cin >> bp[i].se;}
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= k; ++w) {
            if (bp[i].fi <= w) {
                dp[i][w] = max((dp[i-1][w - bp[i].fi] + bp[i].se), dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    
    int ans = 0;
    fre(i, 1, n) {ans = max(ans, dp[i][k]);}
    cout << ans;
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
