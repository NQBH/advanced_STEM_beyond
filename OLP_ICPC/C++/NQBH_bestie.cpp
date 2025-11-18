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
		int g = a[0];
		for (int i = 1; i < n; ++i) g = gcd(g, a[i]);
		if (g == 1) cout << "0\n";
		else {
			int ans;
			for (int i = n - 1; i >= 0; --i)
				if (gcd(g, i + 1) == 1) {
					ans = min(3, n - i);
					break;
				}
			cout << ans << '\n';
		}
	}
}