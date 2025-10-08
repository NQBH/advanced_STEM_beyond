#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        sort(a.begin() + 1, a.end());
        for (int i = 1; i <= n; i += 2) {
            ans = max(ans, abs(a[i + 1] - a[i]));
        }
        cout << ans << endl;
    }
}
