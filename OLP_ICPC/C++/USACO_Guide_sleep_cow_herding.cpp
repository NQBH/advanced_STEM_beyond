#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a(3);
	for (int &b : a) cin >> b;
	sort(a.begin(), a.end());
	/*
	 * The minimum number of moves can only be 0, 1, or 2.
	 * 0 is if they're already consecutive,
	 * 1 is if there's a difference of 2 between any 2 numbers,
	 * and 2 is for all other cases.
	 */
	if (a[0] == a[2] - 2) cout << 0 << '\n';
	else if ((a[1] == a[2] - 2) || (a[0] == a[1] - 2)) cout << 1 << '\n';
	else cout << 2 << '\n';
	// max is equal to largest difference between end & middle, minus 1
	cout << max(a[2] - a[1], a[1] - a[0]) - 1;
}