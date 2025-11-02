#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, n_odd = 0;
		cin >> n;
		vector<int> a(n);
		for (int &x : a) {
			cin >> x;
			if (x & 1) ++n_odd;
		}
		if (n == 1 || !n_odd || n_odd == n) {
			cout << "0\n";
			continue;
		}
		sort(a.begin(), a.end());
		if ((a[0] ^ a[n - 1]) & 1) {
			int l = 1, r = n - 2;
			while (!((a[l] ^ a[l - 1]) & 1)) ++l;
			// cout << "l = " << l << '\n';
			while (!((a[r] ^ a[r + 1]) & 1)) --r;
			// cout << "r = " << r << '\n';
			cout << min(l, n - 1 - r) << '\n';
		} 
		else cout << "0\n";
	}
}