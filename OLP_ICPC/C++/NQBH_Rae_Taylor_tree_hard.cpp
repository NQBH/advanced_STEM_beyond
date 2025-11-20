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
		vector<int> p(n + 1, 0), pmin(n + 1, INT_MAX), smax(n + 1, INT_MIN);
		map<int, int> pos;
		for (int i = 1; i <= n; ++i) {
			cin >> p[i];
			pos[p[i]] = i;
		}
		pmin[1] = p[1];
		for (int i = 2; i <= n; ++i) pmin[i] = min(pmin[i - 1], p[i]);
		smax[n] = p[n];
		for (int i = n - 1; i >= 1; --i) smax[i] = max(smax[i + 1], p[i]);
		bool ok = true;
		for (int i = 1; i < n; ++i) {
			if (pmin[i] > smax[i + 1]) {
				ok = false;
				break;
			}
		}
		if (!ok) cout << "No\n";
		else {
			cout << "Yes\n";
			// build tree
			if (p[1] == 1) {
				for (int i = 2; i <= n; ++i) cout << "1 " << p[i] << '\n';
				continue;
			}
			if (p[n] == n) {
				for (int i = 1; i < n; ++i) cout << p[i] << ' ' << n << '\n';
				continue;
			}
			if (pos[1] < pos[n]) {
				for (int i = pos[1] + 1; i <= n; ++i)
					cout << "1 " << p[i] << '\n';
				for (int i = 1; i < pos[1]; ++i)
					cout << p[i] << ' ' << n << '\n';
				continue;
			}
			if (pos[n] < pos[1]) {
				for (int i = 1; i < pos[n]; ++i) cout << p[i] << ' ' << n << '\n';
				for (int i = pos[1] + 1; i <= n; ++i) cout << "1 " << p[i] << '\n';
				for (int i = pos[n] + 1; i < pos[1]; ++i)
					if (pmin[i - 1] < p[i]) cout << pmin[i - 1] << ' ' << p[i] << '\n';
					else if (p[i] < smax[i + 1]) cout << p[i] << ' ' << smax[i + 1] << '\n';
				cout << pmin[pos[n]] << ' ' << smax[pos[1]] << '\n';
				continue;
			}
			/*
			int n_edge = n - 1;
			vector<bool> visited(n + 1, false);
			visited[1] = true;
			for (int i = pos[1] + 1; i <= n; ++i) { // edge 1 & all numbers after it: too greedy?
				cout << "1 " << p[i] << '\n';
				visited[p[i]] = true;
				--n_edge;
			}
			visited[n] = true;
			for (int i = 1; i < pos[n]; ++i) { // edge a n with any a before n in p
				if (!visited[p[i]]) {
					cout << p[i] << ' ' << n << '\n';
					visited[p[i]] = true;
					--n_edge;
				}
			}
			if (!n_edge) continue; // done n - 1 edge
			for (int i = 1; i <= n; ++i) {
				if (!visited[i]) {
					for (int j = 1; j < pos[i]; ++j) {
						if (p[j] < i) {
							cout << p[j] << ' ' << i << '\n';
							visited[i] = true;
							--n_edge;
							break;
						}
					}
				}
			}
			if (n_edge == 1) cout << pmin[pos[n]] << ' ' << smax[pos[1]] << '\n';
			*/
		}
	}
}