#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, q, t, x;
	cin >> n >> q;
	vector<int> p(n);
	for (int& i : p) cin >> i;
	sort(p.begin(), p.end());
	if (n <= 2) cout << 0 << '\n';
	else {
		int ans = p[n - 1] - p[0], max_dist = 0;
		for (int i = 0; i < n - 1; ++i)
			if (p[i + 1] - p[i] > max_dist) max_dist = p[i + 1] - p[i];
		ans -= max_dist;
		cout << ans << '\n';
	}
	while (q--) {
		cin >> t >> x;
		if (t == 0) p.erase(remove(p.begin(), p.end(), x), p.end());
		if (t == 1) p.insert(lower_bound(p.begin(), p.end(), x), x);
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