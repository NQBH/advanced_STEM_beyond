#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e16;

int SUM(int n) {
    return n * (n + 1) / 2;
}
signed main() {
    int t; cin >> t;

    while (t--) {
        int n, x, y; cin >> n >> x >> y;
        if (x == y) {
            cout << 0 << endl;
            continue;
        }
        int elementOfX = n / x;
        int elementOfY = n / y;
        int LCM = lcm(x, y);
        int elementOfBoth = n / LCM;

        /*
        X = chứa n / x - n / LCM số lớn nhất
        Y = chứa n / y - n / LCM số nhỏ nhất
        Còn lại là: n/LCM số trùng nhau cứ cho random cũng không ảnh hưởng.
        VD: n = 7, x = 2, y = 3
        -> X = [_, 6, 7]
           Y = [1, _]
        */

        int ans = 0;
        int X = SUM(n) - SUM(n - n / x + n / LCM);
        int Y = SUM(n / y - n / LCM);
        ans = X - Y;
        cout << ans << endl;

    }
}