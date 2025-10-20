#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, num_even = 0, ans = 0;
		cin >> n;
		vector<int> a(n), b(n);
		for (int &x : a) {
			cin >> x;
			if (x % 2 == 0) ++num_even;
		}
		for (int &x : b) cin >> x;
		if (num_even >= 2) {
			cout << 0 << '\n';
			continue;
		}
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j)
				if (gcd(a[i], a[j]) > 1) {
					ok = true;
					break;
				}
			if (ok) break;
		}
		if (ok) {
			cout << ans << '\n';
			continue;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j)
				if (gcd(a[i] + 1, a[j]) > 1 || gcd(a[i], a[j] + 1) > 1) {
					ok = true;
					ans = 1;
					break;
				}
			if (ok) break;
		}
		if (ok) cout << ans << '\n';
		else {
			if (num_even == 0) {
				cout << 2 << '\n';
				continue;
			}
			else { // num_even = 1
				cout << 1 << '\n';
				continue;
			}
		}
	}
}
// TLE test 6