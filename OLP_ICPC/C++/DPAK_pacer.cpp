#include <bits/stdc++.h>
#define int long long
using namespace std;

const int oo = 1e9 + 7;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        int last[2] = {0, 0};

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int temp = a[i] - last[0];

            if (last[1] == b[i]) {
                if (temp % 2 == 0) {
                    ans += temp;
                }
                else {
                    ans += temp - 1;
                    // (0, 0) , (1, 1) , (2, 0) , (3, 0)
                }
            }
            else {
                if (temp % 2 == 0) {
                    ans += temp - 1;
                }
                else {
                    ans += temp;
                }
            }
            last[0] = a[i];
            last[1] = b[i];
        }

        ans += (m - last[0]);
        cout << ans << endl;
    }
    return 0;
}