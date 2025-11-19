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
		vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) cin >> a[i][j];
		if (n == 1 && m == 1) {
			cout << "-1\n";
			continue;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				cout << a[(i + 1) % n][(j + 1) % m] << ' ';
			cout << '\n';
		}
	}
}