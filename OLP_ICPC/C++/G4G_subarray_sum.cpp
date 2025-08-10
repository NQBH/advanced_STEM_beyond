#include <iostream>
#include <vector>
using namespace std;

// function to find a continuous subarray whose sum = a given number
vector<int> subarray_sum_naive(vector<int> arr, int target) { // O(n^2) time & O(1) space
	vector<int> res;
	int n = arr.size();
	for (int s = 0; s < n; ++s) { // pick a staarting point for a subarray
		int curr = 0; // current sum from starting & ending indices
		// consider all ending points for the picked starting point
		for (int e = s; e < n; ++e) {
			curr += arr[e];
			if (curr == target) {
				res.push_back(s + 1);
				res.push_back(e + 1);
				return res;
			}
		}
	}
	return {-1}; // if no satisfying subarray is found
}

vector<int> subarray_sum_sliding_window(vector<int>& arr, int target) {
	int s = 0, e = 0; // initialize window
	vector<int> res;
	int curr = 0; // current calculated sum
	for (size_t i = 0; i < arr.size(); ++i) {
		curr += arr[i];
		// if current sum becomes >=, set end & try adjusting start
		if (curr >= target) {
			e = i;
			// while current is greater, remove starting elements of current window
			while (curr > target && s < e)
				curr -= arr[s++];
			if (curr == target) { // if found a satisfying subarray
				res.push_back(s + 1);
				res.push_back(e + 1);
				return res;
			}
		}
	}
	return {-1}; // if no satisfying subarray is found
}

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	vector<int> res = subarray_sum_sliding_window(a, x);
	for (int ele : res) cout << ele << " ";
}