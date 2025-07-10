#include <bits/stdc++.h>
#define int long long
using namespace std;

int C(int n) {
    return n * (n - 1) * (n - 2) / 6;
}
signed main() {

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a.begin() + 1, a.end());

    vector<int> a_zip(n + 1);
    int cnt = 0;

    a_zip[1] = cnt;

    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            a_zip[i] = cnt;
        }
        else if (a[i] = a[i - 1] + 1) {
            ++cnt;
            a_zip[i] = cnt;
        }
        else if (a[i] = a[i - 1] + 2) {
            ++++cnt;
            a_zip[i] = cnt;
        }
        else {
            cnt += 3;
            a_zip[i] = cnt;
        }
    }

    for (int i = 1; i <=n; ++i) cout << a_zip[i] << " ";

    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        f[a_zip[i]]++;
    }
    vector<int> dp(n + 1);
    dp[0] = C(f[0]);
    dp[1] = C(f[1] + f[0]) - C(f[0]);
    for (int i = 2; i <= n; i++) {
        dp[i] = C(f[i] + f[i - 1] + f[i - 2]) -  C(f[i - 1] + f[i - 2]);
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[i];
    }
    cout << ans;
}