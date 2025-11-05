#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    ll t; cin >> t;
    while (t--) {
        cin >> n;
        string a; cin >> a;
        ll cnt = 0, c = a[0];
        ll index = 1;
        while (true) {
            if (c ^= a[index]) break;
            index++;
            if (index == n) break;
        }
        if (!c) cout << 0 << "\n";
        else {
            for (ll i = 0; i < n - 1; ++i) {
                ll k = 0;
                if (a[i] == '1') {
                    for (ll j = i + 1; j < n; ++j) {
                        if (a[j] == '0') {
                            k = j;
                        }
                    }
                    if (k == 0) break;
                    char tm = a[i];
                    a[i] = a[k];
                    a[k] = tm;
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}