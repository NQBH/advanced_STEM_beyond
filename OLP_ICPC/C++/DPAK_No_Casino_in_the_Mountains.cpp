#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1), f(n + 1, 0), prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (1 - a[i]);
        }

        f[0] = 1;
        for (int i = k; i <= n; i++) {
            int cnt = 0;
            if (i > 1) f[i] = f[i - 1];
            cnt = prefix[i] - prefix[i - k];
            if (cnt == k) {
                f[i] = max(f[i], (i - k - 1 > 0 ? f[i - k - 1] : 0) + 1);
//                cout << "(" << i << ", " << f[i - k - 1] << ", " << f[i] << ")" << " ";
            }
        }
        cout << f[n] << endl;
    }
}