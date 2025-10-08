// https://codeforces.com/contest/1418/problem/D
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, q, t, x, max_dist = second_max_dist = 0;
	cin >> n >> q;
	vector<int> p(n), idx_max_dist; // idx_max_dist consists of all indices i s.t. |p[i + 1] - p[i]| = max_dist
	for (int& i : p) cin >> i;
	sort(p.begin(), p.end());
	if (n <= 2) cout << 0 << '\n';
	else {
		int ans = p[n - 1] - p[0];
		for (int i = 0; i < n - 1; ++i) {
			if (p[i + 1] - p[i] > max_dist) {
				second_max_dist = max_dist;
				max_dist = p[i + 1] - p[i];
				idx_max_dist.clear();
				idx_max_dist.push_back(i);
			}
			else if (p[i + 1] - p[i] == max_dist) idx_max_dist.push_back(i);
		}
		ans -= max_dist;
		cout << ans << '\n';
	}
	while (q--) {
		cin >> t >> x;
		if (t == 0) {
			int idx = distance(p.begin(), find(p.begin(), p.end(), x)); // p[idx] = x
			cout << "idx = " << idx << '\n';
			p.erase(remove(p.begin(), p.end(), x), p.end());
			if (p[idx] - p[idx - 1] > max_dist) {
				second_max_dist = max_dist;
				max_dist = p[idx] - p[idx - 1];
				idx_max_dist.clear();
				idx_max_dist.push_back(idx - 1);
			}
			else if (p[idx] - p[idx - 1] == max_dist) idx_max_dist.push_back(idx - 1);
		}
		if (t == 1) {
			auto insert_pos = lower_bound(p.begin(), p.end(), x);
			int idx = insert_pos - p.begin();
			cout << "idx = " << idx << '\n';
			if (idx == 0)  {
				if (p[0] - x == max_dist) idx_max_dist.push_back(0);
				else if (p[0] - x > max_dist) {
					second_max_dist = max_dist;
					max_dist = p[0] - x;
					idx_max_dist.clear();
					idx_max_dist.push_back(0);
				}
			}
			else if (idx == p.size()) {
				if (x - p.back() == max_dist) idx_max_dist.push_back(idx - 1);
				else if (x - p.back() > max_dist) {
					second_max_dist = max_dist;
					max_dist = x - p.back();
					idx_max_dist.clear();
					idx_max_dist.push_back(idx - 1);
				}			
			} else if (p[idx] - p[idx - 1] == max_dist && idx_max_dist.size() == 1) { // if p[idx] - p[idx - 1] == max_dist && idx_max_dist.size() == 2 then max_dist will not be changed after insertion
				max_dist = second_max_dist; // á quân soán ngôi quán quân
				// fail here: need 3rd_max_dist?
			}
			p.insert(insert_pos, x);
		}
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