#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int y, x; cin >> y >> x;
        if (x == y) {
            int m = max(x, y);
            m *= m;
            m = m - min(x, y) + 1;
            cout << m << endl;
        }
        else if (x > y) {
            if (x % 2 == 1) {
                int m = x;
                m *= m;
                m = m - y + 1;
                cout << m << endl;
            }
            else {
                int m = (x - 1) * (x - 1) + 1;
                m = m + y - 1;
                cout << m << endl;
            }
        }
        else {
            if (y % 2 == 0) {
                int m = y * y;
                m = m - x + 1;
                cout << m << endl;
            }
            else {
                int m = (y - 1) * (y - 1) + 1;
                m = m + x - 1;
                cout << m << endl;
            }
        }
    }
}