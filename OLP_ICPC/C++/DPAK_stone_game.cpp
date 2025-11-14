#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int posOne = -1, posN = -1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) posOne = i;
            if (a[i] == n) posN = i;
        }
        if (posOne > posN) swap(posOne, posN);
        int ans = min(posOne + (n - posN + 1), min(posN, n - posOne + 1));
        cout << ans << endl;

    }
    return 0;
}