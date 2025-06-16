/*
Source: ACM Mid-Central United States 2001.
IDs for online judges: POJ 1003, UVA 2294.
Status: Accepted
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {

	double n;
	vector<double> f(277, 0.00);

	for (int i = 1; i <= 276; i++) {
		f[i] = f[i - 1] + (1.0 / (1.0 * i + 1));
	}

	while (cin >> n && n != 0.00) {
		int ans = 0;

		int l = 1, r = 276;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (f[mid] == n) {
				ans = mid;
				break;
			}
			if (f[mid] > n) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		cout << ans << " card(s)" << endl;
	}
}