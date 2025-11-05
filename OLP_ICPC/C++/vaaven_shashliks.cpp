#include <iostream>
using namespace std;

void solve() {
	int t, a, b, x, y;
	cin >> t >> a >> b >> x >> y;
	auto solve = [&](int t, int a, int b, int x, int y) {
		int cur = 0;
		cur += max((t - a + x) / x, 0);
		t -= max((t - a + x) / x, 0) * x;
		cur += max((t - b + y) / y, 0);
		return cur;
	};
	cout << max(solve(t, a, b, x, y), solve(t, b, a, y, x)) << endl;
}

signed main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int q = 1;
	cin >> q;
	while (q-- > 0) solve();
}