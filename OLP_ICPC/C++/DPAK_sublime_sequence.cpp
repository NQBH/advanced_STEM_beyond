#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> x >> n;
        if (n % 2 == 0) cout << 0;
        else cout << x;
        cout << endl;
    }
}