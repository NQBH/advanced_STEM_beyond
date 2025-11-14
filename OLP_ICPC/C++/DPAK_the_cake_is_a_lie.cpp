#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        int ans = 1 * (m - 1) + (n - 1) * m;
        cout << (ans == k ? "YES" : "NO") << endl;

    }
    return 0;
}