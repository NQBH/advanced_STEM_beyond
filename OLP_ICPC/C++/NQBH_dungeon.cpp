#include <bits/stdc++.h>
using namespace std;

bool sortbyCond(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first != b.first) return (a.first > b.first);
	else return (a.second < b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, ans = 0;
		cin >> n >> m;
		vector<int> a(n), b(m), c(m);
		for (int &x : a) cin >> x;
		sort(a.begin(), a.end());
		for (int &x : b) cin >> x;
		for (int &x : c) cin >> x;
		vector<pair<int, int>> cb(m);
		for (int i = 0; i < m; ++i) {
			cb[i].first = c[i];
			cb[i].second = b[i];
		}
		sort(cb.begin(), cb.end(), sortbyCond); // too greedy???
		// for (auto e : cb) cout << e.first << ' ' << e.second << '\n';
		for (int i = 0; i < m; ++i) {
			auto it = lower_bound(a.begin(), a.end(), cb[i].second);
			if (it != a.end()) { // can kill this monster
				if (cb[i].first > 0) *it = max(*it, cb[i].first);
				else *it = 0;
				++ans;
				sort(a.begin(), a.end());
			} else continue; // can't kill this monster
		}
		cout << ans << '\n';
	}
}