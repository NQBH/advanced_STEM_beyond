#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int &x : a) cin >> x;
		if (m < n) cout << "-1\n";
		else if (m == n) {
			if (n == 2) cout << "-1\n";
			else {
				cout << 2 * accumulate(a.begin(), a.end(), 0) << '\n';
				for (int i = 1; i < n; ++i) cout << i << ' ' << i + 1 << '\n';
				cout << 1 << ' ' << n << '\n';
			}
		}
	}
}