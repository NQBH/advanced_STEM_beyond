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

const ll MOD = 1000000007;

bool Primed(ll n) {
    if (n < 2) {return 0;}
    if (n == 2 || n == 3 || n == 5 || n == 7 || n == 11) {return 1;}
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 11 == 0) {return 0;}
    for (ll i = 13; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 4) == 0) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    ll n; cin >> n;
    for (ll i = n + 1; i <= n + 1000; ++i) {
        if (Primed(i)) {
            cout << i << el
                ret
        }
    }
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
