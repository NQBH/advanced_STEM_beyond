#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll s =  0;
        while (n) {
            s += n;
            n >>= 1;
        }
        cout << s << "\n";
    }
}
