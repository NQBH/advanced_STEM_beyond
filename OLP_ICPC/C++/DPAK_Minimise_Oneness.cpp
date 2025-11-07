#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << '0';
        if (n > 1) {
            cout << '1';
            for (int i = 3; i <= n; i++) {
                cout << '0';
            }
        }
        cout << endl;
    }
}
