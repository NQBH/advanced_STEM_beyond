#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    int n, t; cin >> n >> t;
    vector<int>a(n + 1);
    for (int i = 1; i < n; i++) cin >> a[i];
    int cur = 1;
    for ( ; cur + a[cur] <= n; ) {
        cur = cur + a[cur];
        if (cur == t) {
            cout << "YES";
            return 0;
        }
        if (cur == n) break;
    }
    cout << "NO";
}
