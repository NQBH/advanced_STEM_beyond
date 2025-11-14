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
		vector<string> s(n);
		for (int i = 0; i < n; ++i) cin >> s[i];
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			for (int i = 0; i < n; ++i) {
				if (cnt == 0 && s[i][j] == 'v') {
					++cnt;
					break;
				}
				if (cnt == 1 && s[i][j] == 'i') {
					++cnt;
					break;
				}
				if (cnt == 2 && s[i][j] == 'k') {
					++cnt;
					break;
				}
				if (cnt == 3 && s[i][j] == 'a') {
					++cnt;
					break;
				}
			}
		}
		cout << (cnt == 4 ? "YES\n" : "NO\n");
	}
}