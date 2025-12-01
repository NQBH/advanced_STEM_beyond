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

vector<ll> maxSubArraySum(const vector<ll>& arr) {
	ll max_so_far = arr[0], current_max = arr[0];
	int start_index = 0, end_index = 0, temp_start = 0;  // Temporary starting index for current_max
	for (int i = 0; i < arr.size(); ++i) {
		current_max += arr[i];
		if (current_max > max_so_far) {
			max_so_far = current_max;
			start_index = temp_start;
			end_index = i;
		}
		if (current_max < 0) {
			current_max = 0;
			temp_start = i + 1;
		}
	}
	return {max_so_far, start_index, end_index};
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
		if (!(k & 1)) cout << max_subarray_sum << '\n';
		else {
			ll best = 0;
			vector<ll> A = maxSubArraySum(a);
			ll S = A[0], l = A[1], r = A[2];
			cout << A[0] << ' ' << A[1] << ' ' << A[2] << '\n';
			if (l) {
				if (a[l - 1] + b[l - 1] > 0) best = max(best, a[l - 1] + b[l - 1]);
			}
			if (r < n - 1) {
				if (a[r + 1] + b[r + 1] > 0) best = max(best, a[r + 1] + b[r + 1]);
			}
			ll max_idx = l;
			for (ll i = 1; i <= r; ++i)
				if (b[i] > b[max_idx]) max_idx = i;
			best = max(best, b[max_idx]);
			cout << A[0] + best << '\n';
		}
		/*
		int max_idx = 0;
		for (int i = 1; i < n; ++i)
			if (b[i] > b[max_idx]) max_idx = i;
		if (!b[max_idx] || !k) {
			cout << max_subarray_sum(a) << '\n';
			continue;
		}
		*/
		/*
		a[max_idx] += (k & 1 ? 1 : 0) * b[max_idx];
		cout << max_subarray_sum(a) << '\n';
		*/
		/*
		vector<int> op(n, 0);
		priority_queue<pair<ll, int>> pq, pqB;
		for (int i = 0; i < n; ++i)
			if (b[i] > 0) pq.push({b[i], i}); // A wants i s.t. b[i] > 0 & big
		int A = (k + 1) / 2, B = k / 2;
		for (int i = 0; i < A && !pq.empty(); ++i) {
			auto [val, idx] = pq.top();
			++op[idx];
			pq.pop();
			pq.push({val, idx});
		}
		for (int i = 0; i < n; ++i)
			if (b[i] > 0) pqB.push({b[i], i});
		for (int i = 0; i < B && !pqB.empty(); ++i) {
			auto [val, idx] = pqB.top();
			--op[idx];
			pqB.pop();
			pqB.push({val, idx});
		}
		vector<ll> a_final(n);
		for (int i = 0; i < n; ++i)
			a_final[i] = a[i] + (ll)op[i] * b[i];
		cout << max_subarray_sum(a_final) << '\n';
		*/

	}
}