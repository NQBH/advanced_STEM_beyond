#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        bool e = false, o = false;
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] % 2 == 0) e = true;
            else o = true;
        }
        if (o and e) sort(a.begin(), a.end());
        for (ll i = 0; i < n; ++i) cout << a[i] << " ";
        cout << "\n";
    }
}
