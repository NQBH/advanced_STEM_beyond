#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		int ans = 0, prev, next;
		cin >> n;
		vector<int> a(n + 1);
		vector<bool> ok(n + 1, false);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		if (a[1] == a[n]) ok[1] = ok[n] = true;
		if (a[1] == a[2]) ok[1] = ok[2] = true;
		for (int i = 2; i <= n; ++i) {
			if (ok[i - 1]) continue;
			if (!ok[i]) {
				if (i == 1) {
					prev = n;
					next = 2;
				} else if (i == n) {
					prev = n - 1;
					next = 1;
				} else {
					prev = i - 1;
					next = i + 1;
				}
				if (a[i] == a[prev]) ok[i] = ok[prev] = true;
				else if (a[i] == a[next]) ok[i] = ok[next] = true;
				else if (a[prev] == a[next]) {
					ans += abs(a[i] - a[prev]);
					a[i] = a[prev];
					ok[prev] = ok[i] = ok[next] = true;
				} else { // a[prev], a[i], a[next] pairwise distinct
					if (abs(a[prev] - a[i]) <= abs(a[i] - a[next])) {
						ans += abs(a[prev] - a[i]);
						a[i] = a[prev];
						ok[prev] = ok[i] = true;
					} else {
						ans += abs(a[next] - a[i]);
						a[i] = a[next];
						ok[next] = ok[i] = true;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}