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
		vector<string> a(n);
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			for (int j = 0; j < 4; ++j)
				if (a[i][j] == '#') {
					ans.push_back(j + 1);
					break;
				}
		}
		for (int i = n - 1; i >= 0; --i) cout << ans[i] << ' ';
		cout << '\n';
	}
}