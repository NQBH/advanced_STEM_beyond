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
    while (true) {
        int n, ans = 0;
        cin >> n;
        if (n == -1) {break;}
        vector<int> a;
        a.pb(n);
        while (true) {
            cin >> n;
            if (n == 0) {break;}
            a.pb(n);
        }
        sort(all(a));
        int p1 = 0;
        if ((a[p1]*2) == a[1]) {++ans;}
        frs(i, 2, a.size()) {
            frs(j, p1, a.size()-1) {
                if (a[i] == a[j]*2) {++ans;}
                elif (a[i] < a[j]*2) {p1 = j; break;}
            }
        }
        cout << ans << el
    }
}

SORAI {
    Sanic_speed
    int t = 1;// cin >> t;
    wh(t) {solve();}
}

/*
     /\__/\
    ( • 3• )
     / >♥️<\
*/
