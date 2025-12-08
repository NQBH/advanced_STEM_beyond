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
		int n, k, n_lim = 30;
		cin >> n >> k;
		vector<int> f(k + 1, 0); // f[x] = number of friends with capacity >= x
		vector<pair<int, int>> friends; // {capacity, index}
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			if (!x) continue; // useless friend
			// if already have enough friends with capacitty >= x, skip
			if (f[x] < n_lim) {
				friends.push_back({x, i});
				for (int c = 1; c <= x; ++c) ++f[c]; // update counts for all capacities covered
			}
		}
		// dp[s][v] = minimum penalty to form a sequence of cards summing up to s, with last batch having value v
		// minimize penalty sum i_r(v_r - v_{r-1}), ans = (n + 1)v - penalty
		vector<vector<ll>> dp(k + 1, vector<ll>(k + 1, inf));
		dp[0][0] = 0;
		for (auto& e : friends) {
			int capacity = e.first, idx = e.second;
			for (int s = k; s >= 0; --s) {
				// find min(dp[s][u] - idx * u)
				ll curr_best = inf;
				if (dp[s][0] != inf) curr_best = dp[s][0]; // init curr_best with case u = 0
				int max_v = min(capacity, k - s);
				for (int v = 1; v <= max_v; ++v) {
					if (curr_best != inf) {
						ll new_penalty = curr_best + 1ll * idx * v;
						if (new_penalty < dp[s + v][v]) dp[s + v][v] = new_penalty;
					}
					if (dp[s][v] != inf) {
						ll val = dp[s][v] - 1ll * idx * v;
						if (val < curr_best) curr_best = val;
					}
				}
			}
		}
		ll ans = 0;
		for (int s = 0; s <= k; ++s)
			for (int v = 0; v <= k; ++v)
				if (dp[s][v] != inf) {
					ll happiness = 1ll * (n + 1) * v - dp[s][v];
					if (happiness > ans) ans = happiness;
				}
		cout << ans << '\n';
	}
}