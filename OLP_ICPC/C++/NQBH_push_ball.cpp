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
		vector<vector<char>> a(n, vector<char>(m));
		vector<vector<char>> blocked_left(n, vector<char>(m, false)), blocked_top(n, vector<char>(m, false));
		bool ok = true;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) cin >> a[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] == '0') {
					for (int k = j + 1; k < m; ++k)
						if (!blocked_left[i][k]) blocked_left[i][k] = true;
					for (int k = i + 1; k < n; ++k)
						if (!blocked_top[k][j]) blocked_top[k][j] = true;
				}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] == '1' && blocked_left[i][j] == true && blocked_top[i][j] == true) ok = false;
		cout << (ok ? "YES\n" : "NO\n");
	}
}