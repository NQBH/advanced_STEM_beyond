#include <iostream>
#include <vector>
using namespace std;

int max_sum(vector<int>& arr, int k) {
	int n = arr.size();
	if (n <= k) return -1; // invalid size
	// compute sum of 1st window of size k
	int max_sum = 0;
	for (int i = 0; i < k; ++i) max_sum += arr[i];
	// compute sums of remaining windows by removing 1st element of previous window & adding last element of current window
	int window_sum = max_sum;
	for (int i = k; i < n; ++i) {
		window_sum += arr[i] - arr[i - k];
		max_sum = max(max_sum, window_sum);
	}
	return max_sum;
}

int main() {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		vector<int> a(n);
		for (int& i : a) cin >> i;
		cout << max_sum(a, k) << '\n';
	}
}