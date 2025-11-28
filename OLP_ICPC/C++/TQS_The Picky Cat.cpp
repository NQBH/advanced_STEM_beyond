#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            a[i] = abs(a[i]);
        }
        if (n <= 2) {
            cout << "YES" << "\n";
        }
        else {
            ll b = a[0];
            ll m = n / 2;
            sort(a.begin(), a.end());
            if (b <= a[m]) {
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
}
