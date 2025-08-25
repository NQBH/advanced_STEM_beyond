#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int &t : x) cin >> t;
	for (int &t : y) cin >> t;
	int max_squared = 0; // store the current maximum
	for (int i = 0; i < n; ++i) // for each 1st point
		for (int j = i + 1; j < n; ++j) { // for each 2nd point
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			int square = dx * dx + dy * dy;
			/*
			 * if the square of the distance between the two points is
			 * greater than our current maximum, then update the maximum
			 */
			max_squared = max(max_squared, square);
		}
	cout << max_squared << '\n';
}