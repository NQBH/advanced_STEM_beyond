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

SORAI {
    Sanic_speed
    int i = 1, n, x;
    cin >> n >> x;
    int a[n];
    vector<ll> dp;
    frs(i, 0, n) {cin >> a[i];}
    sort(a, a+n);
    dp.pb(0);
    while (i < a[0]) {
        dp.pb(0);
        ++i;
    }
    dp.pb(1);
    for (i = i + 1; i <= x; ++i) {
        dp.pb(0);
        frs(j, 0, n) {
            if (a[j] == i) {
                ++dp[i];
                break;
            } elif (a[j] > i) {
                break;
            } else {
                int check = i - a[j];
                if (dp[check] != 0) {
                    dp[i] += dp[check];
                }
            }
        }
        dp[i] %= M;
    }
    cout << dp[x];
}