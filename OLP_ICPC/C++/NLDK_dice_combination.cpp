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
    int n; cin >> n;
    ll dp[1000002];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = dp[1] + dp[2] + dp[3] + 1;
    dp[5] = dp[1] + dp[2] + dp[3] + dp[4] + 1;
    dp[6] = dp[1] + dp[2] + dp[3] + dp[4] + dp[5] + 1;
    fre(i, 7, n) {
        dp[i] = ((dp[i-6] + dp[i-5] + dp[i-4] + dp[i-3] + dp[i-2] + dp[i-1]) % M);
    }
    cout << dp[n];
}