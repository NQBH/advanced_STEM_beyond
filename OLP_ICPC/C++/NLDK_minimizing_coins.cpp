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
    int n; cin >> n;
    int x; cin >> x;
    int i = 0;
    int a[n], dp[1500009];
    frs(i, 0, n) {cin >> a[i];}
    sort(a, a+n);
    if (x < a[0]) {
        cout << -1; 
        Ret
    } else {
        while (i < a[0]) {
            dp[i] = 0;
            ++i;
        }
        dp[i] = 1;
        for (i = i + 1; i <= x; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[j] == i) {
                    dp[i] = 1;
                    break;
                } elif (a[j] > i) {
                    break;
                } else {
                    int check = i - a[j];
                    if (dp[check] != 0) {
                        if (dp[i] == 0) {
                            dp[i] = dp[check] + 1;
                        } else {
                            dp[i] = min(dp[i], dp[check] + 1);
                        }
                    }
                }
            }
        }
    }
    if (dp[x] == 0) {
        cout << -1;
    } else {cout << dp[x];}
}