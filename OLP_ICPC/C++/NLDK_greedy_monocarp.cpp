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
    int n, k; cin >> n >> k;
    int a[n];
    frs(i, 0, n) {cin >> a[i];}
    sort(a, a+n, greater<int>());
    int total = a[0];
    frs(i, 1, n) {
        total += a[i];
        if (total == k) {
            cout << 0 << el
            ret
        } elif (total > k) {
            cout << (k - (total - a[i])) << el
            ret
        }
    }
    cout << k - total << el
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
