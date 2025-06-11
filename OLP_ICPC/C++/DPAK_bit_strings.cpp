#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main() {

    int n; cin >> n;
    int p2 = 2;
    for (int i = 2; i <= n; i++) {
        (p2 *= 2) %= mod;
    }
    cout << p2;
}