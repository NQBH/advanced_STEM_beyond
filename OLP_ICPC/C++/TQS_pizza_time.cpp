#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t; cin >> t;
    t++;
    while (--t) {
        ll n; cin >> n;
        if (n % 2 == 0) cout << n / 2 - 1 << "\n";
        else cout << n / 2 << "\n";
    }
}
