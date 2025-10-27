#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    ll t; cin >> t;
    ll x;
    ll s;
    while (t--) {
        ll n; cin >> n;
        if (n == 1) {
            cout << 1 << " " << 1 << "\n";
            continue;
        }
        ll a[2 * n + 1] = {0};
        s = n;
        ll i = 1;
        ll j;
        while (i + s <= n * 2 and s >= 1) {
            j = i;
            if (a[j] != 0) {
                i++;
                continue;
            }
            x = s;
            while (i + x <= n * 2 and a[j + x] != 0) x += s;
            if (i + x > n * 2) {
                j++;
                continue;
            }
            a[j] = a[j + x] = s;
            s--;
            i += 1;
        }
        for (ll i = 1; i <= n * 2; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}


