#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int idx = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == n) {
                idx = i;
                break;
            }
        }
        int l = idx - 1, r = idx + 1;
        bool ok = true;
        int cur = a[idx];
        while (l >= 1 && r <= n) {
            bool check = false;
            if (a[l] == cur - 1) {
                check = true;
                l--;
            }
            if (a[r] == cur - 1) {
                check = true;
                r++;
            }
            if (check == false) {
                ok = false;
                break;
            }
            cur--;
        }
        while (l >= 1) {
            bool check = false;
            if (a[l] == cur - 1) {
                check = true;
                l--;
            }
            if (check == false) {
                ok = false;
                break;
            }
            cur--;
        }
        while (r <= n) {
            bool check = false;
            if (a[r] == cur - 1) {
                check = true;
                r++;
            }
            if (check == false) {
                ok = false;
                break;
            }
            cur--;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}