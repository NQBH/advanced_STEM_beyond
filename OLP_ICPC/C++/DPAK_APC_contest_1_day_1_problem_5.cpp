#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        vector<int>save;
        int ans = 0;
        int p = 1;
        while (p <= r2) {
            save.push_back(p);
            p = p * k;
        }
        for (auto p : save) {
            int l = max(l1, (l2 + p - 1) / p);
            int r = min(r1, r2 / p);
            if (l <= r) ans += r - l + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
sinh các k^t <= r2, với mỗi k^i, cần tìm x sao cho x thuộc [l1 .. r1] và x*p thuộc [l2 .. r2]
==> tìm đoạn giao nhau giữa [l1 .. r1] và [l2/p .. r2/p]
*/
