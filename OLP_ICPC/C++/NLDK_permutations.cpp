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
    int n; cin >> n;
    if (n == 1) {
        cout << 1;
    } elif (n <= 3) {
        cout << "NO SOLUTION";
    } elif (n == 4) {
        cout << "3 1 4 2";
    } else {
        int step = 2;
        if (n & 1) {
            int st = n / 2 + 2;
            for (int i = st; i <= n; ++i) {
                cout << i << " " << step << " ";
                ++step;
            }
            cout << 1;
        } else {
            int st = n / 2 + 1;
            for (int i = st; i <= n; ++i) {
                cout << i << " ";
                if (i < n) {
                    cout << step << " ";
                    ++step;
                }
            }
            cout << 1;
        }
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
