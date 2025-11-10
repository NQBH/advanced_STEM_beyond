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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int subn = sqrt(n);
    double pren = sqrt(n);
    double judn = pren - subn;
    if (judn != 0) {
        cNo
        ret
    }
    sort(all(s));
    int cozero = 0, coone;
    frs(i, 0, s.size()) {
        if (s[i] == '0') {
            ++cozero;
        } else break;
    }
    coone = s.size() - cozero;
    if (coone == 0) {
        cNo
        ret
    }
    if ((sqrt(n)-2) == sqrt(cozero)) {
        cYes
    } else {cNo}
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