/*
    VTP - Point Location Test
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int dot = (x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1);
    int det = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    double angle = atan2(det, dot);
    if (angle == 0 || angle == M_PI || angle == -M_PI) cout << "TOUCH\n";
    else if (angle > 0) cout << "LEFT\n";
    else cout << "RIGHT\n";
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}