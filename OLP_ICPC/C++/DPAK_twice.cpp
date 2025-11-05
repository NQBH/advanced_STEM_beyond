#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(21, 0);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            a[x]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += a[i] / 2;
        }
        cout << ans << endl;
    }
}
