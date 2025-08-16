#include <iostream>
#include <climits>
using namespace std;

int main() {
	int t, n, k, sum, ans = INT_MIN;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n - k + 1; ++i) {
			sum = 0;
			for (int j = i; j < i + k; ++j) sum += a[j];
			ans = max(ans, sum);
		}
		cout << ans << '\n';
	}
}