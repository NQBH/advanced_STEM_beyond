#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll m, n, x, y;
int main()
{
    ll t; cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y;
        vector<ll> a(n), b(m);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;
        cout << m + n << "\n";
    }
}
