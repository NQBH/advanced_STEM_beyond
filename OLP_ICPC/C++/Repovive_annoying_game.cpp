#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadane(vector<ll>& a) {
	ll max_ending = a[0], max_so_far = a[0];
	for (int i = 1; i < (int)a.size(); ++i) {
		max_ending = max(a[i], max_ending + a[i]);
		max_so_far = max(max_so_far, max_ending);
	}
	return max_so_far;
}

ll solve_with_boost(vector<ll>& a, vector<ll>& b) {
	int n = a.size();
	// dp[boosted] = {not_in_subarray, in_subarray}
	// We track max sum ending here with 0 or 1 boosts used
	ll ans = LLONG_MIN;
	ll no_boost = 0; // max sum ending here, no boost used
	ll with_boost = LLONG_MIN / 2; // max sum ending here, boost used
	for (int i = 0; i < n; ++i) {
		ll val = a[i];
		ll boosted_val = a[i] + b[i];
		// New states:
		// no_boost: extend previous no_boost, or start fresh
		// with_boost: extend previous with_boost, or use boost now (from no_boost), or start fresh with boost
		ll new_no_boost = max(val, no_boost + val);
		ll new_with_boost = max({boosted_val, no_boost + boosted_val, with_boost + val});
		no_boost = new_no_boost;
		with_boost = new_with_boost;
		ans = max({ans, no_boost, with_boost});
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll k;
		cin >> n >> k;
		vector<ll> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		if (k % 2 == 0) cout << kadane(a) << '\n'; // Bob cancels all Alice's moves
		else cout << solve_with_boost(a, b) << '\n'; // Alice gets 1 uncanceled boost
	}
}