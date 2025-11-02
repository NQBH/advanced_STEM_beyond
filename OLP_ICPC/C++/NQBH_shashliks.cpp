#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int k, a, b, x, y, ans = 0;
		cin >> k >> a >> b >> x >> y;
		if (k < min(a, b)) {
			cout << "0\n";
			continue;
		}
		if (x > y) {
			while (k >= b) {
				++ans;
				k -= y;
			}
			while (k >= a) {
				++ans;
				k -= x;
			}
			cout << ans << '\n';
		} else if (x == y) {
			while (k >= a) {
				++ans;
				k -= x;
			}
			while (k >= b) {
				++ans;
				k -= y;
			}
			cout << ans << '\n';
		} else { // x < y
			while (k >= a) {
				++ans;
				k -= x;
			}
			while (k >= b) {
				++ans;
				k -= y;
			}
			cout << ans << '\n';
		}
	}
}