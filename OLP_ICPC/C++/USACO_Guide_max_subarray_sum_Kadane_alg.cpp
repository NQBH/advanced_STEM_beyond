#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<ll> x(n);
	for (ll &i : x) cin >> i;
	ll current_sum = x[0], max_subarray_sum = x[0];
	for (int i = 1; i < n; ++i) {
		/*
		 * Continue the subarray sum or start a new
		 * subarray sum beginning at the current element.
		 */
		current_sum = max(current_sum + x[i], x[i]);
		// store the maximum subarray sum at each iteration
		max_subarray_sum = max(max_subarray_sum, current_sum);
	}
	cout << max_subarray_sum << '\n';
}