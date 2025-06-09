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

void solve() {
    ull a, b;
    ull ans;
    cin >> a >> b;
    if (a == b) {
        if (a == 1) {ans = 1;}
        else {
            /*
            if (a & 1) {
                ans = (a - 1) * (a - 1);

            } else {

            }
            */
            ans = (a - 1) * (a - 1) + a;
        }
    } elif (a < b) {
        if (b % 2 == 0) {
            ans = (b - 1) * (b - 1);
            ans += a;
        } else {
            ans = (b - 1) * (b - 1) + b;
            ans += (b - a);
        }
    } else {
        if (a % 2 == 1) {
            ans = (a - 1) * (a - 1);
            ans += b;
        } else {
            ans = (a - 1) * (a - 1) + a;
            ans += (a - b);
        }
    }
    cout << ans << el
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
