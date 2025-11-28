#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        if (n == 1 or n == 3) cout << -1 << "\n";
        else if (n == 4) cout << 3366 << "\n";
        else if (n == 2) cout << 66 << "\n";
        else {
            for (ll i = 0; i < n - 4; ++i) {
                cout << 3;
            }
            if (n % 2 == 0) cout << 3366 <<  "\n";
            else cout << 6366 <<  "\n";

        }
    }
}
