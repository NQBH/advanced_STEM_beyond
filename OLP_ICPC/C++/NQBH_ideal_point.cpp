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
		vector<int> l(n), r(n);
		map<int, int> f;
		for (int i = 0; i < n; ++i) {
			cin >> l[i] >> r[i];
			if (k >= l[i] && k <= r[i])
				for (int j = l[i]; j <= r[i]; ++j) ++f[j];
		}
		bool ok = true;
		if (!f[k]) {
			cout << "NO\n";
			continue;
		}
		for (auto e : f) {
			if (e.first != k && e.second >= f[k]) {
				ok = false;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}