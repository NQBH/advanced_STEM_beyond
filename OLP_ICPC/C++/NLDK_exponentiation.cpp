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

const int M = 1000000007;

ll Powering(ll a, ll b) {
    if (b == 0) {return 1;}
    elif (b == 1) {return a;}
    ll temp = Powering(a, b/2);
    temp = (temp*temp) % M;
    if (b % 2) {
        temp = (temp * a) % M;
    }
    return temp;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    if (b == 0) {
        cout << 1 << el
    } elif (a == 0) {
        cout << 0 << el
    } elif (b == 1) {
        cout << a << el
    } else {
        cout << Powering(a, b) << el
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
