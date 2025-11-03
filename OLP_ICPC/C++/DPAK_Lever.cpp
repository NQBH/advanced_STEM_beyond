#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        bool ok = true;
        int cnt = 0;
        while (ok) {
            ok = false;
            for (int i = 1; i <= n; i++) {
                if (a[i] > b[i]) {
                    a[i]--;
                    ok = true;
                    break;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] < b[i]) {
                    a[i]++;
                    break;
                }
            }
            cnt++;
        }
        cout << cnt << endl; 

    }
}