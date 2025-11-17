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
		vector<int> p(m + 1), ans(n + 2, -1);
		set<int> S;
		for (int i = 1; i <= m; ++i) {
			cin >> p[i];
			S.insert(p[i]);
			if (n - (int)S.size() + 1 >= 0) ans[n - (int)S.size() + 1] = i;
		}
		for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
		cout << '\n';
	}
}
// WA test 1