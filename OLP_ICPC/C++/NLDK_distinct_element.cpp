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
#define mp make_pair
#define pf push_front
#define pb push_back
#define popf pop_front
#define popb pop_back
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
    int n, start = 2; cin >> n;
    ll a[n + 1], b[n + 1];
    fre(i, 1, n) {cin >> b[i];}
    a[1] = 1;
    fre(i, 2, n) {
        if ((b[i] - b[i - 1]) == i) {
            a[i] = start;
            ++start;
        } else {
            a[i] = a[i - (b[i] - b[i - 1])];
        }
    } 
    fre(i, 1, n) {cout << a[i] << " ";}
    cel
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
