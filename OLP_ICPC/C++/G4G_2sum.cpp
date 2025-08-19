#include <iostream>
#include <vector>
using namespace std;

bool two_sum_naive(vector<int>& arr, int target) { // O(n^2) time & O(1) space
	int n = arr.size();
	for (int i = 0; i < n; ++i) // consider all pairs (arr[i], arr[j])
		for (int j = i + 1; j < n; ++j)
			if (arr[i] + arr[j] == target) return true; // check if the sum of the current pair equals the target
	return false; // if no pair is found after checking all pairs
}

bool two_sum_2_pointers(vector<int>& arr, int target) {
	int left = 0, right = arr.size() - 1;
	while (left < right) {
		int sum = arr[left] + arr[right];
		if (sum == target) return true;
		else if (sum < target) ++left; // move toward a possibly higher sum
		else --right; // move toward a lower sum
	}
	return false; // if no pair is found
}

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	cout << two_sum_naive(a, x) << '\n';
	cout << two_sum_2_pointers(a, x);
}