#include <iostream>
using namespace std;

int main() {
	int n, t, count, sum, l, r, ans = 0;
	cin >> n >> t;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (l = 0; l < n; ++l) { // count max number of books that can be read from l-th book
		count = 0; // reset count
		sum = 0; // reset sum from point l to pointer r
		for (r = l; r < n; ++r) {
			sum += a[r];
			if (sum > t) break;
			else ++count;
		}
		ans = max(ans, count);
	}
	cout << ans;
}
// TLE test 9 CodeForces