#include <bits/stdc++.h>
#define APC signed
#define int long long
using namespace std;

const int oo = 1e9;

APC main() {
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        if (x == y) {
            cout << -1 << endl;
            continue;
        }
        if (x > y) {
            if (x - 1 > y && y > 1) cout << 3;
            else cout << -1;
        }
        else {
            cout << 2;
        }
        cout << endl;
    }
}
