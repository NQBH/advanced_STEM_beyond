#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n; cin >> n;
    while (n--) {
        ll a, b; cin >> a >> b;
        cout << ((b + 1) / 2 - a / 2) / 2 << "\n";
    }
}
