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
#define pobf pop_front
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
    int k, a, b, x, y, ans;
    cin >> k >> a >> b >> x >> y;
    if (k < a && k < b) {
        cout << ans << el
        ret
    }
    if (x == y) {
        ans = (k - min(a, b)) / x + 1;
    } elif (x < y) {
        if (k >= a) { 
            ans = (k - a) / x + 1;
            k -= ans * x;
            if (k >= b) {
                ans += (k - b) / y + 1;
            }
        } else {
            ans += (k - b) / y + 1;
        }
    } else {
        if (k >= b) {
            ans = (k - b) / y + 1;
            k -= ans * y;
            if (k >= a) {
                ans += (k - a) / x + 1;
            }
        } else {
            ans += (k - a) / x + 1;
        }
    }
    cout << ans << el
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