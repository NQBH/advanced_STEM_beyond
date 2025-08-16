#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max_sum(vector<int>& arr, int k) {
	int n = arr.size();
	int max_sum = INT_MIN;
	for (int i = 0; i <= n - k; ++i) { // consider all blocks starting with i
		int current_sum = 0;		
		for (int j = 0; j < k; ++j) current_sum += arr[i + j]; // calculate sum of current subarray of size k
		max_sum = max(current_sum, max_sum); // update result if required
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