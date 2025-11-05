#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<char> a(n + 1, '^');
        for (int i = 1; i <= n; i++) cin >> a[i];
        /*
        vector<char> b = a;
        sort(b.begin() + 1, b.end());
        if (a == b) {
            cout << 0 << endl;
            continue;
        }
        */
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += 1 - (a[i] - '0');
        }
        int ans = 0;
        for (int i = 1; i <= cnt; i++) {
            ans += a[i] - '0';
        }
        cout << ans << endl;
    }
}