#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<int> x(n), y(n);
	for (int& i : x) cin >> i;
	for (int& i : y) cin >> i;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			int x_diff = x[i] - x[j], y_diff = y[i] - y[j];
			ans = max(ans, x_diff * x_diff + y_diff * y_diff);
		}
	cout << ans << '\n';
}