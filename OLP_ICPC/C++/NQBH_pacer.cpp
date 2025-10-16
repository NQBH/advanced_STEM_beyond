#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, ans = 0;
		cin >> n >> m;
		vector<int> a(n + 1), b(n + 1);
		a[0] = 0, b[0] = 0;
		for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
		for (int i = 1; i <= n; ++i) {
			int diff = a[i] - a[i - 1];
			if (diff % 2) ans += diff - (b[i] == b[i - 1]);
			else ans += diff - (b[i] != b[i - 1]);
		}
		if (a[n] != m) ans += m - a[n];
		cout << ans << '\n';
	}
}