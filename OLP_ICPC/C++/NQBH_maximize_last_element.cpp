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
		if (n == 1) cout << a[0] << '\n';
		else {
			int ans = 0;
			for (int i = 0; i < n; i += 2)
				ans = max(ans, a[i]);
			cout << ans << '\n';
		}
	}
}