#include <iostream>
#include <vector>
using namespace std;

// return LIS of subarray ending with index i: time complexity: exponential & space complexity: linear
int lis_end_at_idx(vector<int>& arr, int idx) { // compute L[i]
	if (idx == 0) return 1; // base case
	// consider all elements on the left of i, recursively compute LISs ending with them & consider the largest
	int mx = 1;
	for (int prev = 0; prev < idx; ++prev)
		if (arr[prev] < arr[idx])
			mx = max(mx, lis_end_at_idx(arr, prev) + 1);
	return mx;
}

int lis(vector<int>& arr) {
	int n = arr.size();
	int res = 1;
	for (int i = 1; i < n; ++i) res = max(res, lis_end_at_idx(arr, i));
		return res;
}

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << lis(a);
}