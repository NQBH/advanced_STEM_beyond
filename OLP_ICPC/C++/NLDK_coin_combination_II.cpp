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
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

const int M = 1000000007;

SORAI {
    Sanic_speed
    int n, k;
    cin >> n >> k;
    int a[n];
    frs(i, 0, n) {cin >> a[i];}
    sort(a, a+n);
    long dp[1000002];
    fill_n(dp, k+1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int w = 1; w <= k; ++w) {
            if (w - a[i] >= 0) {
                dp[w] += dp[w - a[i]];
                dp[w] %= M;
            }
        }
    }
    cout << dp[k];
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
