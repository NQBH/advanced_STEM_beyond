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

int counter = 1;

void solve() {
    double long x, y;
    cin >> x >> y;
    double long e_radius = sqrt(x*x + y*y);
    double long area = 0;
    int year = 1;
    cout << "Property " << counter << ": This property will begin eroding in year ";
    while (true) {
        area += 100;
        double long radius = sqrt(area/M_PI); 
        if (radius >= e_radius) {
            cout << year;
            break;
        }
        ++year;
    }
    cout << "." << el
    ++counter;
}

SORAI {
    //Sanic_speed
    int t; cin >> t;
    wh(t) {solve();}
    cout << "END OF OUTPUT.";
}

/*
     /\__/\
    ( • 3• )
    / >♥️<\
*/
