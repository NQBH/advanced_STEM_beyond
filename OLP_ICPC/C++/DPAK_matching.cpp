#include <bits/stdc++.h>
#define int long long
using namespace std;

int C(int n) {
    if (n < 0) return 0;
    return n * (n - 1) / 2;
}

signed main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        s = " " + s;
        int ans = -1;
        if (s[1] == '0') {
            ans = 0;
        }
        else {
            int n = s.size() - 1;
            ans = 1;
            for (int i = 1; i <= n; i++) {
                if (s[i] == '?') {
                    if (i == 1) {
                        ans *= 9;
                    }
                    else ans *= 10;
                }
            }
        }
        cout << ans << endl;
    }
}
