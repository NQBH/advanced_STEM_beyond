#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define Sanic_speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Ret return 0;
#define ret return;
#define all(x) x.begin(), x.end()
#define el "\n";
#define elif else if
#define ll long long int
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define popf pop_front
#define pops pop_back
#define mp make_pair
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

SORAI {
    Sanic_speed
    int t = 1, p = 0, m; cin >> t;
    char c;
    wh(t) {
        cin >> c >> m;
        if (c == 'P') {p += m;}
        else {
            if (m > p) {
                cYES
                p = 0;
            } else {
                cNO
                p -= m;
            }
        }
    }
}

/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
