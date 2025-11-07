#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k1, k2; cin >> n >> k1 >> k2;
        int w, b; cin >> w >> b;

        int canPlaceWhite = min(k1, k2) + (max(k1, k2) - min(k1, k2)) / 2;
        int canPlaceBlack = min(n - k1, n - k2) + (max(n - k1, n - k2) - min(n - k1, n - k2)) / 2;

        if (w <= canPlaceWhite && b <= canPlaceBlack) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
