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
		vector<int> p(n + 1, 0), pmin(n + 1, 0), smax(n + 1, 0);
		// map<int, int> pos;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
			// pos[p[i]] = i;
		}
		pmin[1] = p[1];
		for (int i = 2; i <= n; ++i) pmin[i] = min(pmin[i - 1], p[i]);
		smax[n] = p[n];
		for (int i = n - 1; i >= 1; --i) smax[i] = max(smax[i + 1], p[i]);
		// int min_pos = pos[1];
		bool ok = true;
		for (int i = 1; i < n; ++i) {
			if (pmin[i] > smax[i + 1]) {
				ok = false;
				break;
			}
		}
		cout << (ok ? "Yes\n" : "No\n");
	}
}