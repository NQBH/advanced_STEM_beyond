#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, c, ans = 0;
		cin >> n >> c;
		vector<int> a(n);
		map<int, int> f;
		for (int &x : a) {
			cin >> x;
			++f[x];
		}
		if (c == 1) {
			cout << f.size() << '\n';
			continue;
		}
		for (auto e : f)
			if (e.second >= c) ans += c;
			else ans += e.second;
		cout << ans << '\n';
	}
}