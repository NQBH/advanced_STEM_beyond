#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, l, x, y;
	cin >> n >> m >> l >> x >> y;
	vector<int> s(n), t(n), p(m);
	for (int i = 0; i < n; ++i) cin >> s[i] >> t[i];
	for (int &x : p) cin >> x;
	for (int i = 0; i < m; ++i) {
		double ans = l - p[i]; // person i just walk
		for (int j = 0; j < n; ++j) { // bus j
			if (s[j] > p[i]) continue;
			double cur_time = 1.0 * (t[j] - s[j]) / x; // person i waits bus j to get on & then go to t[j]
			cur_time += 1.0 * (l - t[j]) / y;
			ans = min(ans, cur_time);
		}
		cout << ans << '\n';
	}
}
// WA test 8 ICPC