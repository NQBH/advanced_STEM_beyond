#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define eln "\n";
#define elif else if
#define ll long long int
#define fi first
#define se second
#define cYES cout << "YES" << "\n";
#define cNO cout << "NO" << "\n";
#define cYes cout << "Yes" << "\n";
#define cNo cout << "No" << "\n";
#define frs(i, a, b) for(ll i = a; i < b; ++i)
#define fre(i, a, b) for(ll i = a; i <= b; ++i)
#define el "\n";
#define wh(t) while (t--)
#define SORAI int main()
#define fileinout(name) freopen(name".INP", "r", stdin);freopen(name".OUT", "w", stdout);
using namespace std;
 
void solve() {
    int n, ans = 0, status = -1; cin >> n;
    int a[n];
    frs(i, 0, n) {cin >> a[i]; status *= -1; ans += (status * a[i]);}
    cout << ans << el
}
 
SORAI {
    Sanic_speed
    int t; cin >> t;
    wh(t) {solve();}
}
 
/**
     /\__/\
    ( • 3• )
     / >♥️<\
**/
