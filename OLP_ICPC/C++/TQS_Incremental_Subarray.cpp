#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> a;
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        a.resize(m + 1);
        a[0] = 0;
        bool check = false;
        for (ll i = 1; i <= m; ++i) {
            cin >> a[i];
            if (a[i] <= a[i - 1] or (a[i] - a[i - 1] > 1 and i != 1)) {
                check = true;
            }
        }
        if (check == true) {
            cout << 1 << "\n";
            continue;
        }
        else {
            cout << n - a[m] + 1 << "\n";
        }
    }
}
