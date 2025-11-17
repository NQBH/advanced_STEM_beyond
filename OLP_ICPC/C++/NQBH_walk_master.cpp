#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d, ans = 0;
		cin >> a >> b >> c >> d;
		if (d < b) {
			cout << "-1\n";
			continue;
		}
		// move up (a, b) -> (a + d - b, d)
		a += d - b;
		ans += d - b;
		b = d;
		if (c > a) cout << "-1\n";
		else {
			ans += a - c;
			cout << ans << '\n';
		}
	}
}