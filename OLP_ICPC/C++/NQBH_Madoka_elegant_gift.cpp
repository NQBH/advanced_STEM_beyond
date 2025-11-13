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
		vector<string> a(n);
		for (string &x : a) cin >> x;
		bool ok = true;
		for (int i = 0; i < n - 1; ++i)
			for (int j = 0; j < m - 1; ++j) {
				int n1 = 0;
				if (a[i][j] == '1') ++n1;
				if (a[i + 1][j] == '1') ++n1;
				if (a[i][j + 1] == '1') ++n1;
				if (a[i + 1][j + 1] == '1') ++n1;
				if (n1 == 3) {
					ok = false;
					break;
				}
			}
		cout << (ok ? "YES\n" : "NO\n");
	}
}