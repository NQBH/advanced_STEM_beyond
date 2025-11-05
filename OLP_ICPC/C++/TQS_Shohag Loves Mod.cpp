#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        for (ll i = 1; i <= n; i++) {
            cout << i * 2 - 1 << " ";
        }
        cout << "\n";
    }
}
