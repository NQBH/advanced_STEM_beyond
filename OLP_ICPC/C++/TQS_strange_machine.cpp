#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n, q; cin >> n >> q;
        string A;
        cin >> A;
        bool b = true;
        for (char a : A) {
            if (a == 'B') b = false;
        }
        while (q--) {
            ll a; cin >> a;
            if (b) {
                cout << a << "\n";
                continue;
            }
            ll i = 0;
            ll cnt = 0;
            while (a != 0) {
                if (A[i] == 'A') a--;
                else a /= 2;
                i++;
                if (i == n) i = 0;
                cnt++;
            }
            cout << cnt << "\n";
        }
    }
}
