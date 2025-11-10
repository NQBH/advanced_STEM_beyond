#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define eln "\n";
#define elif else if
#define ll long long int
#define fi first
#define se second
#define frs(i, a, b) for(ll i = a; i < b; ++i)
#define fre(i, a, b) for(ll i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
#define fileinout(name) freopen(name".INP", "r", stdin);freopen(name".OUT", "w", stdout);
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const long long INFLL = (long long)1e18 + 7;

void solve() {
    int n;
    cin >> n;
    int a[n];
    frs(i, 0, n) {cin >> a[i];}
    if (n > 2 || ((a[1] - a[0]) == 1)) {
        cout << "NO" << eln
    } else {cout << "YES" << eln}
}

SORAI {
    Sanic_speed
    int t;
    cin >> t;
    wh(t) {
        solve();
    }
}

/**
     /\__/\
    ( • 3• )
     / >♥️<\
**/