#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> h(n + 1), w(n + 1);
		for (int i = 1; i <= n; ++i) cin >> h[i] >> w[i];
		for (int i = 1; i <= n; ++i) {
			bool ok = false;
			for (int j = 1; j <= n; ++j) {
				if (j == i) continue;
				if (h[j] < h[i] && w[j] < w[i]) {
					cout << j << " ";
					ok = true;
					break;
				}
				if (w[j] < h[i] && h[j] < w[i]) {
					cout << j << " ";
					ok = true;
					break;
				}
			}
			if (!ok) cout << -1 << " ";
		}
		cout << '\n';
	}
}
// TLE on test 4 CodeForces