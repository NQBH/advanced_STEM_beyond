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

SORAI{
    Sanic_speed
    while (true) {
        int step = 1;
        ll ans = 0;
        string s;
        string line;
        getline(cin, line);
        istringstream iss(line);
        while (iss >> s) {
            if (s[0] == '#') { Ret }
            frs(i, 0, s.size()) {
                ans += (s[i] - 'A' + 1) * step;
                ++step;
            }
            ++step;
        }
        cout << ans << el
    }
}
/**
     /\__/\
    ( • 3• )
    / >♥️<\
**/
