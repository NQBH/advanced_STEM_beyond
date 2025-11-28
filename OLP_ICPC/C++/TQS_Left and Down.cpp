#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    while (t--) {
        ll a, b, k; cin >> a >> b >> k;
        if ((a / gcd(a, b) <= k and b / gcd(a, b) <= k)) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
}
