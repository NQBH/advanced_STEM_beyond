#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int>a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            bool check = true;
            for (int j = 1; j <= n && check; j++) {
                if (i != j) {
                    int cur = abs(a[i] - a[j]);
                    if (cur % k == 0) {
                        check = false;
                    }
                }
            }
            if (check == true) {
                ans = i;
                break;
            }
        }
        if (ans == -1) cout << "NO";
        else cout << "YES" << endl << ans;
        cout << endl;
    }
}
