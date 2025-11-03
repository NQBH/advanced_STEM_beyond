#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        if (n == 1 or m == 1 or (n == 2 and m == 2)) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}
