#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n, k1, k2; cin >> n >> k1 >> k2;
        ll w, b; cin >> w >> b;
        if ((w * 2 <= k1 + k2) and b * 2 <= (n * 2 - (k1 + k2))) {
            cout << "YES" << "\n";
            continue;
        }
        else cout << "NO" << "\n";
    }
}
