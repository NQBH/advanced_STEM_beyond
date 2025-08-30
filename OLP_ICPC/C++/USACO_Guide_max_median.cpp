#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int last_true(int lo, int hi, function<bool(int)> f) {
	// if none of the values in the range work, return lo - 1
	--lo;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) lo = mid;
		else hi = mid - 1;
	}
	return lo;
}

int main() {
	int size, max_ops;
	cin >> size >> max_ops;
	vector<int> arr(size);
	for (int &i : arr) cin >> i;
	sort(arr.begin(), arr.end());
	cout << last_true(1, 2e9, [&](int x) { // use 2e9 instead of INT32_MAX to avoid overflow
		// return true if the median can be raised to x
		long long ops_needed = 0;
		for (int i = (size - 1) / 2; i < size; ++i) ops_needed += max(0, x - arr[i]);
		return ops_needed <= max_ops;
	}) << '\n';
}