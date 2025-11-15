#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        if (y == 1) {
            // Every round removes everything (positions 1,2,3,...)
            cout << -1 << "\n";
            continue;
        }

        // We binary search for minimal N where:
        // rem(N) = N - x * floor(N / y) >= k
        
        long long low = 1, high = (long long)4e18, ans = -1;

        while (low <= high) {
            long long mid = (low + high) / 2;

            long long removed = x * (mid / y);
            if (removed < 0) removed = LLONG_MAX; // overflow guard

            long long remain = mid - removed;
            if (remain >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
// WA test 1