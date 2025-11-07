#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll ans = 1;
        ll n;
        cin >> n;
        for (ll i = 3; i <= n * 2; i++) {
            ans = (ans * i) % MOD;
        }
        cout << ans << "\n";
    }
}
