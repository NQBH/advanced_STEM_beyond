#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		// dp[c][v] = minimum sum((v_r - v_{r - 1}) * i_r) for sequence of values summing to c, ending with value v
		vector<vector<ll>> dp(k + 1, vector<ll>(k + 1, inf));
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			int lim = min(a[i - 1], k);
			for (int c = k; c >= 0; --c) {
				ll best_diff = inf;
				if (dp[c][0] != inf) best_diff = dp[c][0];
				for (int v = 1; v <= lim; ++v) {
					int prev_u = v - 1;
					if (prev_u > 0) {
						if (dp[c][prev_u] != inf) best_diff = min(best_diff, dp[c][prev_u] - (ll)prev_u * i);
					}
					if (c + v <= k) {
						if (best_diff != inf) dp[c + v][v] = min(dp[c + v][v], best_diff + (ll)v * i);
					}
				}
			}
		}
		ll ans = 0;
		for (int c = 0; c <= k; ++c)
			for (int v = 0; v <= k; ++v)
				if (dp[c][v] != inf) { // happiness = v_p * (n + 1) - penalty
					ll curr_happiness = (ll)v * (n + 1) - dp[c][v];
					ans = max(ans, curr_happiness);
				}
		cout << ans << '\n';
	}
}
// TLE test 11 CF