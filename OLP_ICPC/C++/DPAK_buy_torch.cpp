#include <bits/stdc++.h>
#define int unsigned long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;

        int l = 0, r = 2e18;
        int ans = 0;

        while (l <= r) {
            int mid = (l + r) >> 1;
            // mid = số lần trade 1 stick -> x stick
            // y * k + k <= 1 + mid * (x - 1)
            // đổi k cục than + k que  <= 1 que ban đầu + số slần trade (mỗi lần trade mất 1 que -> mid * (x - 1))
            __int128 have = 1 + (__int128)mid * (x - 1);
            __int128 need = (__int128)k * (y + 1);
            if (have >= need) {
                ans = mid + k;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }
}