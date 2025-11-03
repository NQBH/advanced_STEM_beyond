#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, c, x, ans = 0;
		cin >> n >> c;
		vector<int> a;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (x > c) ++ans;
			else a.push_back(x);
		}
		sort(a.begin(), a.end());
		for (int i = a.size() - 1; i >= 0; --i) {
			if (a[i] > c) ++ans;
			else c /= 2;
		}
		cout << ans << '\n';
	}
}