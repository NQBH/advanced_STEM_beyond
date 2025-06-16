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
#define cel cout << "\n"
#define frs(i, a, b) for(int i = a; i < b; ++i)
#define fre(i, a, b) for(int i = a; i <= b; ++i)
#define wh(t) while (t--)
#define SORAI int main()
using namespace std;
typedef unsigned long long ull;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        if (a % 3 == 0) {cYES}
        else {cNO}
    } elif (a > b) {
        int diff = a - b;
        b -= diff;
        a -= diff * 2;
        if (b < 0) {cNO}
        elif (b == 0) {
            if (a == 0) {cYES}
            else {cNO}
        } else {
            if (a % 3 == 0) {cYES}
            else {cNO}
        }
    } else {
        int diff = b - a;
        a -= diff;
        b -= diff * 2;
        if (a < 0) {cNO}
        elif (a == 0) {
            if (b == 0) {cYES}
            else {cNO}
        } else {
            if (a % 3 == 0) {cYES}
            else {cNO}
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
