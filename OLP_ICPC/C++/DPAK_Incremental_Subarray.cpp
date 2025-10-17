#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int>a(m + 1);
        for (int i = 1; i <= m; i++) {
            cin >> a[i];
        }
        bool check = false;
        for (int i = 1; i < m; i++) {
            if (a[i] + 1 != a[i + 1]) {
                check = true;
                break;
            }
        }
        int ans = 1;
        if (check == false) {
            ans = n - a[m] + 1;
        }
        cout << ans << endl;
    }
}