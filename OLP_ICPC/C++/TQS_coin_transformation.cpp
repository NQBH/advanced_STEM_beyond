#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll cnt = 0;
        while (true) {
            if (n < 4) break;
            cnt++;
            n /= 4;
        }
        cout << (1 << (cnt)) << "\n";
    }
}
