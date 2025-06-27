#include <bits/stdc++.h>
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

void solve() {
    int n, k;
    cin >> n >> k;
    string s[n];
    vector<vector<int>> dp(n, vector<int> (n, 0));
    vector<ll> a(k, 0);
    frs(i, 0, n) cin >> s[i];
    frs(i, 0, k) {
        char c = i + 'A';
        dp = vector<vector<int>>(n, vector<int>(n, 0));
        frs(j, 0, n) {if (s[0][j] == c) dp[0][j] = 1;  a[i] += dp[0][j];}
        frs(j, 1, n) {
            if (s[j][0] == c) {dp[j][0] = 1; a[i] += dp[j][0];}
            frs(m, 1, n) {
                if (s[j][m] == c) {
                    dp[j][m] = 1 + min({dp[j - 1][m], dp[j][m - 1], dp[j - 1][m - 1]});
                    a[i] += dp[j][m];
                } 
            }
        }
    }
    // answer
    frs(i, 0, k) cout << a[i] << el
}

SORAI {
    Sanic_speed
    int t = 1; //cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
