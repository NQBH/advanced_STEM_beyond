#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll max_subarray_sum(const vector<ll>& arr) {
	if (arr.empty()) return 0;
	ll max_ending_here = arr[0];
	ll max_so_far = arr[0];
	for (size_t i = 1; i < arr.size(); ++i) {
		max_ending_here = max(arr[i], max_ending_here + arr[i]);
		max_so_far = max(max_so_far, max_ending_here);
	}
	return max_so_far;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<ll> a(n), b(n);
		for (ll &x : a) cin >> x;
		for (ll &x : b) cin >> x;
		int start_idx = 0, end_idx = 0;
		ll S = a[0];
		for (int i = 0; i < n; ++i) {
			int curS = 0;
			for (int j = i; j < n; ++j) {
				curS += a[j];
				if (curS > S) {
					start_idx = i;
					end_idx = j;
					S = curS;
				}
			}
		}
		// cout << start_idx << ' ' << end_idx << ' ' << S << '\n';
		if (!(k & 1)) cout << S << '\n';
		else {
			ll best = 0;
			if (start_idx) best = max(best, a[start_idx - 1] + b[start_idx - 1]);
			if (end_idx < n - 1) best = max(best, a[end_idx + 1] + b[end_idx + 1]);
			for (int i = start_idx; i <= end_idx; ++i)
				best = max(best, b[i]);
			ll max_idx = 0;
			for (ll i = 0; i < n; ++i)
				if (b[i] > b[max_idx]) max_idx = i;
			a[max_idx] += b[max_idx];
			cout << max(S + best, max_subarray_sum(a)) << '\n';
		}
	}
}