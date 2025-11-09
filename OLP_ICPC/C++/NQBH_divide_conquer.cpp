#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		if (accumulate(a.begin(), a.end(), 0) % 2 == 0) cout << "0\n";
		else {
			int ans = 2e9;
			bool ok1 = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i] % 4 == 1) {
					ok1 = 1;
					break;
				} else if (a[i] % 2 == 0) ans = min(ans, __builtin_ctz(a[i]));
				else { // a[i] % 4 = 3
					int cnt = 0;
					while (a[i] & (1 << cnt)) ++cnt;
					/*
					while (a[i] & 1) {
						a[i] /= 2;
						++cnt;
					}
					*/
					ans = min(ans, cnt);
				}
			}
			if (ok1) cout << "1\n";
			else cout << ans << '\n';
		}
	}
}