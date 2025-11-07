#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t = 1;// cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<vector<char>> a(n + 1, vector<char>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >>a[i][j];
            }
        }
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int cur = 0;
            int cur2 = 0;
            for (int j = 1; j <= n; j++) {
                cur += (a[i][j] == 'C' ? 1 : 0);
                cur2 += (a[j][i] == 'C' ? 1 : 0);
            }
            (ans += cur * (cur - 1) / 2) += cur2 * (cur2 - 1) / 2;
        }
        cout << ans << endl;
    }
}
