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
#define pf push_front
#define popb pop_back
#define popf pop_front
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

const int N = 1500000;
vector<bool> Primer(N + 9, false);

void Sorai_Era_sieve() {
    Primer[0] = Primer[1] = true;
    for (int i = 4; i <= N; i += 2) {Primer[i] = true;}
    for (ll i = 3; i <= N; i += 2) {
        if (!Primer[i]) {
            for (ll j = i * i; j <= N; j += i) {
                Primer[j] = true;
            }
        }
    }
}

void solve() {
    Sorai_Era_sieve();
    //max a: 9307, max d: 346, max n: 210
    while (true) {
        int counter = 0, a, d, n;
        string line;
        getline(cin, line);
        stringstream ss(line);
        ss >> a;
        ss >> d;
        ss >> n;
        if (a == 0 && d == 0 && n == 0) {break;}
        if (!Primer[a]) {++counter;}
        while (counter != n) {
            a += d;
            if (!Primer[a]) {++counter;}
        }
        cout << a << el
    }
}

SORAI {
    Sanic_speed
    int t = 1;// cin >> t;
    wh(t) {solve();}
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
