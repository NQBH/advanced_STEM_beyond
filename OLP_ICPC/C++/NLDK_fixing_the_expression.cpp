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

void solve() {
    vector<char> c(3);
    frs(i, 0, 3) {cin >> c[i];}
    if (c[0] == c[2]) {c[1] = '=';}
    elif (c[0] > c[2]) {c[1] = '>';}
    else {c[1] = '<';}
    frs(i, 0, 3) {cout << c[i];}
    cel
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
