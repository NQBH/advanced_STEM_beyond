#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if(n % 2 == 1) {
            cout << 1 << endl;
            continue;
        }
        int cur = 1;
        int ans = 1;
        for (int i = 2; cur <= n && n % cur == 0 ; i++) {
            cur = lcm(cur, i);
            ans = i;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}