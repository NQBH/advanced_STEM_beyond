#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<char> a(n + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt += (a[i] == '0');
        }
        if (cnt == n) {
            cout << 0 << endl;
            continue;
        }

        cnt = 0;
        if (a[1] == '1') cnt++;

        vector<int> idx;
        for (int i = 2; i <= n; i++) {
            if (a[i] == '1') idx.push_back(i);
        }
        for (auto v : idx) {
            bool check = false;
            for (int i = v - 1; i >= max(1LL, v - k + 1); i--) {
                if (a[i] == '1') check = true;
            }
            if (!check) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
