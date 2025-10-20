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
		int n, num_even = 0;
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
		} // still work upto here
		bool ok0 = false, ok1 = false;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (gcd(a[i], a[j]) > 1) {
					ok0 = true;
					break;
				}
				if (gcd(a[i] + 1, a[j]) > 1 || gcd(a[i], a[j] + 1) > 1) ok1 = true;
			}
			if (ok0) break;
		}
		if (ok0) {
			cout << 0 << '\n';
			continue;
		}
		if (ok1) {
			cout << 1 << '\n';
			continue;
		}
		if (num_even == 1) {
			cout << 1 << '\n';
			continue;
		}
		else { // num_even = 1
			cout << 2 << '\n';
			continue;
		}
	}
}
// TLE test 6 CF