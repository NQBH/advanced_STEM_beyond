#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int k, l1, r1, l2, r2;
		ll ans = 0;
		cin >> k >> l1 >> r1 >> l2 >> r2;
		if (k == 2) {
			for (int i = l1; i <= r1; ++i) {
				int x = i;
				// if (l2 <= x && x <= r2) ++ans;
				while (x <= r2) {
					if (x >= l2) ++ans;
					if (x > r2 / 2) break;
					x <<= 1;
				}
			}
		} else {
			for (int i = l1; i <= r1; ++i) {
				int x = i;
				// if (l2 <= x && x <= r2) ++ans;
				while (x <= r2) {
					if (x >= l2) ++ans;
					if (x > r2 / k) break;
					x *= k;
				}
			}
		}

		cout << ans << '\n';
	}
}