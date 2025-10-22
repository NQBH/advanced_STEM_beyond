#include <bits/stdc++.h>
#define APC signed
#define int long long
using namespace std;

const int oo = 1e9;

APC main() {
    int t; cin >> t;
    while (t--) {
        int c, d; cin >> c >> d;
        if (c == d) {
            int ans = 1;
            if (c == 0) ans = 0;
            cout << ans << endl;
            continue;
        }
        // (a + x, b + y) = (c, d) => (c - x, d - y) = (0, 0)
        // => (c-x, d-y) doi xung sau 1 op => valid ?
        // ex: (3, 5) - 4 -> (-1, 1) -> (0, 0) 
        int dif = (d - c);
        if (dif % 2 == 0) cout << 2;
        else cout << -1;
        cout << endl;
    }
}

