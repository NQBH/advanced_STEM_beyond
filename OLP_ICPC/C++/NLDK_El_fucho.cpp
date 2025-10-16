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
#define mp make_pair
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
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
    int n, m = 0, ans = 1;
    cin >> n;
    while (n > 1) {
        ans += n / 2;
        m += n / 2;
        if (n % 2 == 1) {
            n = (n / 2) + 1;
        } else {
            n /= 2;
        }
        ans += m / 2;
        if (m % 2 == 1) {
            m = (m / 2) + 1;
        } else {
            m /= 2;
        }
    }
    while (m > 1) {
        ans += m / 2;
        if (m % 2 == 1) {
            m = (m / 2) + 1;
        } else {
            m /= 2;
        }
    }
    cout << ans << el
}
 
SORAI {
    Sanic_speed
    int t = 1; cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
