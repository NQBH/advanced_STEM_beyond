#include <bits/stdc++.h>
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

void solve() {
    while (true) {
        char a[2];
        double t = -101.0, d = -101.0, h = -101.0, h2 = -101.0;
        frs(i, 0, 2) {
            cin >> a[i];
            if (a[i] == 'T') {
                cin >> t;
            } elif (a[i] == 'H') {
                cin >> h;
            } elif (a[i] == 'D') {cin >> d;}

            else {ret} //End
        }
        //Missing D
        if (d == -101.0) {
            h2 = h - t;
            double e = h2 / 0.5555 + 10.0;
            d = 1 / (log(e / 6.11) + 5417.7530 * (1 / 273.16)) - 273.16;
        }
        //Finding h if missing either T or H
        if (t == -101.0 || h == -101.0) {
            double e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (d + 273.16))));
            h2 = (0.5555) * (e - 10.0);
        }
        //Missing T
        if (t == -101.0) {
            t = h - h2;
        }
        //Missing H
        if (h == -101.0) {
            h = t + h2;
        }
        //printing answer
        cout << fixed << setprecision(1) << "T " << t << " D " << d << " H " << h << el
    }
}

SORAI {
    //Sanic_speed
    int t = 1;// cin >> t;
    wh(t) {solve();}
}

/*
     /\__/\
    ( • 3• )
    / >♥️<\
*/

/*
humidex = temperature + h
h = (0.5555)*(e - 10.0)
e = 6.11*exp [5417.7530*((1/273.16) - (1/(dewpoint + 273.16)))]
*/
