#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int R, X, D, n; cin >> R >> X >> D >> n;
        string s; cin >> s; s = " " + s;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                cnt++;
                R = max(0LL, R - D);
            }
            else {
                if (R >= X) continue;
                else {
                    cnt++;
                    R = max(0LL, R - D);
                }
            }
        }
        cout << cnt << endl;

    }
}