#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int>a(n + 1), freq(2 * n + 2, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        for (int i = 1; i <= 2 * n; i++) {
            if (freq[i] > 1) freq[i + 1]++;
        }
        int ans = 0;
        for (int i = 1; i <= 2 * n  + 1; i++) {
            ans += (freq[i] > 0);
        }
        cout << ans << endl;

    }
    return 0;
}