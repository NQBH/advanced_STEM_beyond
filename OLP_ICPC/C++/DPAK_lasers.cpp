#include <bits/stdc++.h>
#define int long long
using namespace std;

const int oo = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<int> a(n + 1), b(m + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];

        int resOne = 0, resTwo = 0;

        int f_l = 1, f_r = n;
        while (f_l <= f_r) {
            int mid = f_l + f_r >> 1;
            if (a[mid] <= y) {
                resOne = mid;
                f_l = mid + 1;
            }
            else {
                f_r = mid - 1;
            }
        }

        int s_l = 1, s_r = m;
        while (s_l <= s_r) {
            int mid = s_l + s_r >> 1;
            if (b[mid] <= x) {
                resTwo = mid;
                s_l = mid + 1;
            }
            else {
                s_r = mid - 1;
            }
        }
        
        int res = resOne + resTwo;
        cout << res << endl;
    }
    return 0;
}