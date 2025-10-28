#include <climits>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), c(n);
		for (int &x : a) cin >> x;
		for (int &x : c) cin >> x;
		if (n == 1) {
			cout << "0\n";
			continue;
		}
		vector<int> drop_pos;
		for (int i = 0; i < n - 1; ++i)
			if (a[i] > a[i + 1]) drop_pos.push_back(i);
		if (drop_pos.empty()) {
			cout << "0\n";
			continue;
		}
		// dp0[i] = min cost when pos i is kept
		// dp1[i] = min cost when pos i is changed
		vector<ll> dp0(n, INT_MAX), dp1(n, INT_MAX), last_val0(n), last_val1(n);
		dp0[0] = 0;
		dp1[0] = c[0];
		for (int i = 1; i < n; ++i) {
			// keep a[i]
			ll need_prev = a[i];
			ll best_prev = INT_MAX;
			if (dp0[i - 1] <= dp1[i - 1]) {
				if (last_val0[i - 1] <= need_prev) best_prev = dp0[i - 1];
			} else {
				if (last_val1[i - 1] <= need_prev) best_prev = dp1[i - 1];
			}
			if (best_prev == INT_MAX) best_prev = dp1[i - 1];
			dp0[i] = best_prev;
			last_val0[i] = a[i];
			// change a[i] with cost c[i]
			ll need_prev2 = -INT_MAX;
			ll best_prev2 = INT_MAX;
			if (dp0[i - 1] <= dp1[i - 1]) best_prev2 = dp0[i - 1];
			else best_prev2 = dp1[i - 1];
			if (last_val0[i - 1] > a[i]) best_prev2 = dp1[i - 1];
			dp1[i] = c[i] + best_prev2;
			last_val1[i] = a[i];
		}
		ll ans = min(dp0[n], dp1[n]);
		cout << ans << '\n';
	}
}