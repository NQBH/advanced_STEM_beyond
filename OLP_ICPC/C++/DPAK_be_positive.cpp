#include <bits/stdc++.h>
#define int unsigned long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = 0;
        int neg = 0;
        while (n--) {
            int  x; cin >> x;
            if (x == 0) {
                ans++;
            }
            else if (x == -1) neg++;
        }
        if (neg % 2 == 1) ans+=2;
        cout << ans << endl;
    }
}
