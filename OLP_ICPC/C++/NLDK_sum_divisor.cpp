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
const ll TWO_MOD_INV = 500000004;

ll Summing(ll a, ll b) {
    return ((((a % MOD) * (b % MOD)) % MOD) * TWO_MOD_INV) % MOD;
}

void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 1 << el
            ret
    }
    ll ans = n;
    for (ll i = 2; i <= n / 2; ++i) {
        ll check = n / i;
        if ((n / check) != i) {
            ll gap = (n / check) - i + 1;
            ans = (ans + check * Summing((n / check + i), gap)) % MOD;
            i = n / check;
            continue;
        }
        ans += (check * i);
        ans %= MOD;
    }
    ll back_half = Summing((n + (n / 2 + 1)), ((n / 2) + (n % 2 == 1)));
    ans = (ans + back_half) % MOD;
    cout << ans;
}

SORAI {
    Sanic_speed
    int t = 1;// cin >> t;
    wh(t) {solve();}
}

/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
