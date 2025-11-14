#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        vector<bool> check(n + 1, false);
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (check[i - 1]) continue;
            if (p[i] < p[i - 1]) {
                check[i] = true;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}