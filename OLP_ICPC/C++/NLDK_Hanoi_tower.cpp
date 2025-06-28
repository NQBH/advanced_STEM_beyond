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

vector<pair<int, int>> moves;

void run(int n, int start, int mid, int finish) {
    if (n == 1) {
        moves.pb(make_pair(start, finish));
        ret
    }
    run(n - 1, start, finish, mid);
    moves.pb(make_pair(start, finish));
    run(n - 1, mid, start, finish);
}

void solve() {
    int n; cin >> n;

    run(n, 1, 2, 3);
    cout << moves.size() << el
    frs(i, 0, moves.size()) {
        cout << moves[i].fi << " " << moves[i].se << el
    }
}

SORAI {
    Sanic_speed
    int t = 1; //cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
