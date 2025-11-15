#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (!k) cout << "0\n";
		else {
			int ans = 1;
			k -= n;
			--n;
			while (k > 0) {
				if (k <= n) {
					++ans;
					k -= n;
				} else {
					ans += 2;
					k -= 2 * n;
				}
				--n;
			}
			cout << ans << '\n';
		}
	}
}