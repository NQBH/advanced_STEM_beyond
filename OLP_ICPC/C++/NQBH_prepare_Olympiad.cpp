#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, l, r, x, ans = 0;
	cin >> n >> l >> r >> x;
	vector<int> c(n);
	for (int &x : c) cin >> x;
	for (int mask = 0; mask < (1 << n); ++mask) {
		if (__builtin_popcount(mask) < 2) continue; // must have >= 2 problems
		int sum = 0;
		vector<int> c_curr;
		for (int i = 0; i <= __lg(mask); ++i)
			if (mask & (1 << i)) {
				c_curr.push_back(c[i]);
				sum += c[i];
			}
		sort(c_curr.begin(), c_curr.end());
		if (sum >= l && sum <= r && c_curr.back() - c_curr[0] >= x) ++ans;
	}
	cout << ans << '\n';
}