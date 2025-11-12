#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if (k >= n) {
            cout << 1 << endl;
            continue;
        }
        if (k == 0) {
            cout << n << endl;
            continue;
        }
        int connectedBridge = n - 1;
        if (k >= n - 1) {
            cout << 1;
        }
        else cout << n;
        cout << endl;
    }
}
