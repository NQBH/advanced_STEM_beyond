#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, s, m;
		cin >> n >> s >> m;
		vector<int> l(n), r(n);
		for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
		if (l[0] >= s || m - r[n - 1] >= s) cout << "YES\n";
		else {
			bool ok = false;
			for (int i = 1; i < n; ++i)
				if (l[i] - r[i - 1] >= s) {
					ok = true;
					break;
				}
			cout << (ok ? "YES\n" : "NO\n");
		}
	}
}