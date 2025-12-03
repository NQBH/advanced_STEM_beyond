#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, k, ans = 1e9;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i] % k == 0) a[i] = 0;
			else a[i] = k - a[i] % k;
		}
		if (k != 4) { // 2, 3, 5: primes
			for (int x : a) ans = min(ans, x);
		} else {
			int n_even = 0, n_odd = 0;
			for (int x : a) {
				if (x & 1) ++n_odd;
				else ++n_even;
				ans = min(ans, x);
			}
			// make 2 evens
			if (n_even > 1) ans = 0;
			else if (n_even == 1 && n_odd) ans = min(ans, 1);
			else if (!n_even && n_odd > 1) ans = min(ans, 2);
		}
		cout << ans << '\n';		
	}
}