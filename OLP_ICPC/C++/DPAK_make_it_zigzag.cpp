#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1), f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            f[i] = max(a[i], f[i - 1]);
        }
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                a[i] = f[i];
                if (a[i] == a[i - 1]) {
                    cnt++;
                    a[i - 1]--;
                }
            }
            else {
                if (a[i] >= a[i - 1]) {
                    cnt += abs(a[i] - a[i - 1] + 1);
                    a[i] = a[i - 1] - 1;
                }
            }
        }
        cout << cnt << endl;
    }
}
