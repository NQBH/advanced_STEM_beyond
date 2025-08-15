#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	// static arrays
	int arr[] = {5, 1, 3, 2, 4}, n = 5;
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) cout << arr[i] << " "; // output: 1 2 3 4 5
	cout << '\n';

	int arr2[] = {5, 1, 3, 2, 4};
	sort(arr2 + 1, arr2 + 4);
	for (int i = 0; i < n; ++i) cout << arr2[i] << " "; // output: 5 1 2 3 4

	// dynamic arrays
	vector<int> v{5, 1, 3, 2, 4};
	sort(v.begin(), v.end());
	for (int i : v) cout << i << " "; // output: 1 2 3 4 5
	cout << '\n';

	v = {5, 1, 3, 2, 4};
	sort(v.begin() + 1, v.begin() + 4);
	for (int i : v) cout << i << " "; // output: 5 1 2 3 4
	cout << '\n';

	// dynamic arrays of pairs & tuples
	vector<pair<int, int>> u{{1, 5}, {2, 3}, {1, 2}};
	sort(u.begin(), u.end());
	for (pair<int, int> p : u) cout << p.first << " " << p.second << '\n';
	/*
	 * Outputs:
	 * 1 2
	 * 1 5
	 * 2 3
	 */
}