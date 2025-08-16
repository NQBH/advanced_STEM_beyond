#include <iostream>
using namespace std;

int main() {
	int t, n, k, sum;
	cin >> t;
	while (t--) {
		sum = 0;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < k; ++i) sum += a[i]; // sum of 1st k elements
		int ans = sum; // init answer as sum of 1st k elements
		for (int i = k; i < n; ++i) {
			sum += a[i] - a[i - k];
			ans = max(ans, sum);
		}
		cout << ans << '\n';
	}
}