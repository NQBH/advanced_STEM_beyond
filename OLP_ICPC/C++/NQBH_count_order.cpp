#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;

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
		vector<int> b(n);
		for (int &x : b) cin >> x;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		bool ok = true;
		for (int i = 0; i < n; ++i)
			if (a[i] <= b[i]) {
				ok = false;
				break;
			}
		if (!ok) cout << "0\n";
		else {
			long long ans = 1;
			for (int i = n - 1; i >= 0; --i) {
				int n_choice = n - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());
				ans *= max(0, n_choice - (n - 1 - i));
				ans %= m;
			}
			cout << ans << '\n';
		}
	}
}