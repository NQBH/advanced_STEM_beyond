#include <iostream>
#include <climits>
using namespace std;

int max_xor_subarray (int arr[], int n) { // time complexity: O(n^2) & auxiliary space: O(1)
	int ans = INT_MIN;
	for (int i = 0; i < n; ++i) {
		int curr_xor = 0; // store xor of current subarray
		// pick ending points of subarrays starting with i
		for (int j = i; j < n; ++j) {
			curr_xor = curr_xor ^ arr[j];
			ans = max(ans, curr_xor);
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << max_xor_subarray(a, n);
}
// CSES: accepted: 9/14 (5/14: TLE)