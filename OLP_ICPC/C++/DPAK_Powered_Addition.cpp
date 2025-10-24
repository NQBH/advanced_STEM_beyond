#include <bits/stdc++.h>
#define int long long
using namespace std;
const int oo = 1e16;

signed main() {
    int t; cin >> t;
    vector<int> p2;
    p2.push_back(1);
    for (int i = 1; p2.back() < oo ; i++) {
        p2.push_back(p2.back() * 2);
    }
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        /*
        Tổng giá trị tối đa 1 phần tử nhận được sau T giây = 1 + 2 + 4 + ... + 2^{T-1}
                                                           = 2^T - 1
        Một số nguyên X luôn biểu diễn được dưới dạng: tổng của a.2^i với a ={0, 1}
        */
        int l = 0, r = p2.size() - 1;
        int ans = 0;
        while (l <= r) {
            int mid = l + r >> 1;
            int maxCanIncrease = p2[mid] - 1;
            vector<int> temp = a;
            bool ok = true;
            for (int i = 2; i <= n; i++) {
                if (temp[i] < temp[i - 1]) {
                    int diff = temp[i - 1] - temp[i];
                    if (diff <= maxCanIncrease) {
                        temp[i] += diff;
                    }
                    else {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}