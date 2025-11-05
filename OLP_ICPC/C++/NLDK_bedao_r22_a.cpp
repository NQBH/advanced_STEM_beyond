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
    int n, m, a, b, diff = 0;
    cin >> n >> m;
    if (n % 2) {++diff;}
    if (m == 0) {if (n % 2) {cNO} else {cYES} ret}
    vector<vector<int>> blocking(5009, vector<int>(5009, 0));
    wh(m) {
        cin >> a >> b;
        if (blocking[a][b] == 0) {blocking[a][b] = 1; int sum = a + b; if (sum % 2) {++diff;} else {--diff;}}
    }
    if (diff == 0) {cYES}
    else {cNO}
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
