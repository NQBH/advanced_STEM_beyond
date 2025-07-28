#include <iostream>
using namespace std;

int main() {
	int n, l, r, x, c_min, c_max, sum, ans = 0;
	cin >> n >> l >> r >> x;
	int c[n];
	for (int i = 0; i < n; ++i) cin >> c[i];
	for (int i = 0; i < (1 << n); ++i) {
		c_min = 1000000; // since c_i in [10^6]
		c_max = -1;
		sum = 0;
		for (int j = 0; j < n; ++j)
			if (i & (1 << j)) {
				sum += c[j];
				c_min = min(c_min, c[j]);
				c_max = max(c_max, c[j]);
			}
		if (l <= sum && sum <= r && c_max - c_min >= x) ++ ans;
	}
	cout << ans;
}