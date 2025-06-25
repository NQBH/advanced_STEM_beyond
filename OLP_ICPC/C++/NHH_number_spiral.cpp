#include <iostream>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;

        ll k = max(x, y);
        ll base = (k - 1) * (k - 1);
        ll ans;

        if (k % 2 == 0) {
            if (x == k)
                ans = base + y;
            else
                ans = base + k + (k - x);
        } else {
            if (y == k)
                ans = base + x;
            else
                ans = base + k + (k - y);
        }

        cout << ans << "\n";
    }
    return 0;
}