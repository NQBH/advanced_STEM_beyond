#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int &t : x) cin >> t;
	for (int &t : y) cin >> t;
	double max_dist = 0; // store the current maximum
	for (int i = 0; i < n; ++i) // for each 1st point
		for (int j = i + 1; j < n; ++j) { // for each 2nd point
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			int square = dx * dx + dy * dy;
			max_dist = max(max_dist, sqrt(square));
		}
	cout << (int)pow(max_dist, 2) << '\n';
}