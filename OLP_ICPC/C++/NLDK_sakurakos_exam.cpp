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
#define cyes cout << "YES" << "\n";
#define cno cout << "NO" << "\n";
#define frs(i, a, b) for(ll i = a; i < b; ++i)
#define fre(i, a, b) for(ll i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
#define fileinout(name) freopen(name".INP", "r", stdin);freopen(name".OUT", "w", stdout);
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if ((a+b) == 0) {
        cyes
    } elif (a == 0) {
        if (b % 2 == 0) {
            cyes
        } else {
            cno
        }
    } elif (a % 2 == 0) {
        if (b % 2 == 0) {
            cyes
        } else {
            if (a >= 2) {
                cyes
            } else {
                cno
            }
        }
    } else {
        cno
    }
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