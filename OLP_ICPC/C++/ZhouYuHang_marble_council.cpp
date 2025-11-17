#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5, P = 998244353;
int n, a[N], cnt[N], dp[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	memset(cnt, 0, sizeof cnt);
	int max_cnt = 0;
	for (int i = 1; i <= n; ++i)
		max_cnt = max(max_cnt, ++cnt[a[i]]);
	memset(dp, 0, sizeof dp), dp[0] = 1;
	for (int i = 1; i <= n; ++i)
		if (cnt[i]) {
			for (int j = n; j >= cnt[i]; --j)
				dp[j] = (dp[j] + 1ll * cnt[i] * dp[j - cnt[i]]) % P;
		}
	int ans = 0;
	for (int i = max_cnt; i <= n; ++i)
		(ans += dp[i]) %= P;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
}