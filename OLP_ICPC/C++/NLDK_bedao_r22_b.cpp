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

const int M = 1e9 + 7;

int bit_len(ll n) {
    int res = -1;
    while (n) {++res; n >>= 1;}
    return res;
}

ll Powering(ll n, int k) {
    if (k == 0) {return 1;}
    elif (k == 1) {return n;}
    
    ll temp = Powering(n, k/2) % M;
    temp = (temp * temp % M);
    if (k % 2) {temp = (temp * n) % M;}
    return temp;
}

void solve() {
    ll n, k, ans = 0;
    cin >> n >> k;
    int len = bit_len(k);
    for (int i = 0; i <= len; ++i) {
        int m = (k >> i) & 1;
        if (m == 1) {
            m = i;
            ans += Powering(n, m);
            ans %= M;
        }
    }
    cout << ans % M << el
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
