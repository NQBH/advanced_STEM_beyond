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
#define cYES cout << "YES" << "\n";
#define cNO cout << "NO" << "\n";
#define cYes cout << "Yes" << "\n";
#define cNo cout << "No" << "\n";
#define frs(i, a, b) for(ll i = a; i < b; ++i)
#define fre(i, a, b) for(ll i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
#define fileinout(name) freopen(name".INP", "r", stdin);freopen(name".OUT", "w", stdout);
using namespace std;

void solve() {
    ll n, m;
    cin >> n;
    m = n;
    string ans = "";
    wh(n) {
        string s;
        cin >> s;
        if (s[0] == '#') {
            ans += '1';
        } elif (s[1] == '#') {
            ans += '2';
        } elif (s[2] == '#') {
            ans += '3';
        } else {
            ans += '4';
        }
    }
    for (int i = m - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
    cout << eln
}

SORAI {
    Sanic_speed
    int t;
    cin >> t;
    wh(t) {solve();}
}

/**
     /\__/\
    ( • 3• )
     / >♥️<\
**/