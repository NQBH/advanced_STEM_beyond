#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int n, q, t, x, d, max_dist = 0;
	cin >> n >> q;
	vector<int> p(n + 1);
	vector<map<int, vector<int>>> m; // 1st: distance, 2nd: all indices i such that p[i + 1] - p[i] = d.first
	for (int i = 1; i <= n; ++i) cin >> p[i];
	sort(p.begin(), p.end());
	for (int i = 1; i < n; ++i) {
		int d = p[i + 1] - p[i];
		if (d > max_dist) max_dist = d;
		m[d].push_back(i);
	}

	if (n <= 2) cout << 0 << '\n';
	else cout << p[n] - p[1] - max_dist;

	while (q--) {
		cin >> t >> x;
		if (t == 0) { // remove
			int idx = distance(p.begin(), find(p.begin(), p.end(), x)); // p[idx] = x
			cout << "idx = " << idx << '\n';
			p.erase(remove(p.begin(), p.end(), x), p.end());
			if (idx == 1) {
				d = p[1] - x;
				if (m[d].size() == 1) m.erase(d);
				else m[d].erase(remove(m[d].begin(), m[d].end(), 1), m[d].end());
			} else if (idx == p.size() + 1) {
				d = x - p[p.size()];
				if (m[d].size() == 1) m.erase(d);
				else m[d].erase(remove(m[d].begin(), m[d].end(), p.size() + 1), m[d].end());
			} else {
				d = x - p[idx - 1];
				if (m[d].size() == 1) m.erase(d);
				else m[d].erase(remove(m[d].begin(), m[d].end(), idx - 1), m[d].end());
				d = p[idx] - x;
				if (m[d].size() == 1) m.erase(d);
				else m[d].erase(remove(m[d].begin(), m[d].end(), idx), m[d].end());
			}
			max_dist = m.rbegin()->first;
			else cout << p.back() - p[1] - max_dist;
		}
		if (t == 1) p.insert(lower_bound(p.begin(), p.end(), x), x); // add
		n = p.size();
		if (n <= 2) cout << 0 << '\n';
		else {
			int ans = p[n - 1] - p[0], max_dist = 0;
			for (int i = 0; i < n - 1; ++i)
				if (p[i + 1] - p[i] > max_dist) max_dist = p[i + 1] - p[i];
			ans -= max_dist;
			cout << ans << '\n';
		}
	}
}