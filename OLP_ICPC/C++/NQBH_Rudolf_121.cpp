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
		int l = 0, r = n - 1;
		bool ok = true;
		while (r - l > 1) {
			a[l + 1] -= 2 * a[l];
			if (a[l + 1] < 0) {
				ok = false;
				break;
			}
			a[l + 2] -= a[l];
			if (a[l + 2] < 0) {
				ok = false;
				break;
			}
			a[l] = 0;
			++l;
			a[r - 1] -= 2 * a[r];
			if (a[r - 1] < 0) {
				ok = false;
				break;
			}
			a[r - 2] -= a[r];
			if (a[r - 2] < 0) {
				ok = false;
				break;
			}
			a[r] = 0;
			--r;
		}
		if (!ok) cout << "NO\n";
		else if (a[l] || a[r]) cout << "NO\n";
		else cout << "YES\n";
	}
}