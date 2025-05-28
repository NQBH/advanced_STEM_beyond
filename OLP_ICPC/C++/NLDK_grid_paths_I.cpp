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
    int n;
    cin >> n;
    long dp[n][n];
    string s[n];
    frs(i, 0, n) {cin >> s[i];}
    if (s[0][0] == '*') {
        cout << 0;
        Ret
    } else {
        dp[0][0] = 1;
    }
    frs(i, 1, n) {
        if (s[0][i] == '*') {dp[0][i] = 0;}
        else {dp[0][i] = dp[0][i-1];}
    }
    frs(i, 1, n) {
        if (s[i][0] == '*') {dp[i][0] = 0;}
        else {dp[i][0] = dp[i-1][0];}
    }
    frs(i, 1, n) {
        frs(j, 1, n) {
            if (s[i][j] == '*') {dp[i][j] = 0;}
            else {
                dp[i][j] = ((dp[i-1][j] + dp[i][j-1]) % M);
            }
        }
    }
    cout << dp[n-1][n-1];
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
