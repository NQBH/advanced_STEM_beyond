#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<char> a(n + 1);
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        dp[1] = (a[1] == '@');
        int i = 2;
        for (; i <= n; i++) {
            if (a[i] == '*' && a[i - 1] == '*') break;
            dp[i] = max(dp[i - 1], dp[i - 2]) + (a[i] == '@');
        }
        cout << dp[i - 1] << endl;;
    }
    return 0;
}