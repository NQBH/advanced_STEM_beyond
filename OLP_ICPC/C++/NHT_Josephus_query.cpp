#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fix(ll n, ll k) {
    if (n == 1) return 1;
    if (k <= ((n + 1) / 2)) {
        if (2 * k > n) return (2 * k) % n;
        else return 2 * k;
    }        
    ll tmp = fix(n / 2, k - (n + 1) / 2);
    if (n % 2 == 1) return 2 * tmp + 1;
    else return 2 * tmp - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        cout << fix(n, k) << "\n";
    }
    return 0;
}