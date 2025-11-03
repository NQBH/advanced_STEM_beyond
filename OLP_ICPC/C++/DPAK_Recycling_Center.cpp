#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n, c; cin >> n >> c;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        int idx = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] <= c) idx = i;
            else break;
        }
        if (idx == -1) {
            cout << n << endl;
            continue;
        }
        
        int mul = 1;
        int cnt = 0;
        for (int i = idx + 1; i <= n; i++) {
            cnt++;
        }
        while (idx) {
            int cur = a[idx];
            bool ok = false;
            for (int i = 2; i <= mul; i++) {
                cur *= 2;
                if (cur > c) {
                ok = true;
                break;
                }
            }
            if (ok) {
                cnt++;
            }
            else {
                mul++;
            }
            idx--;
        }
        cout << cnt << endl;
    }
}