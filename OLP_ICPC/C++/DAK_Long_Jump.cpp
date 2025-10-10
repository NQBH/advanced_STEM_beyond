#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<long long> dp(n + 2, 0);

    for (int i = n; i >= 1; i--) {
        long long next_pos = i + a[i];
        if (next_pos > n) dp[i] = a[i];
        else dp[i] = a[i] + dp[next_pos];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        if (dp[i] > ans)
            ans = dp[i];
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
