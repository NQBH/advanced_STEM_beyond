#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<int> a(n);
		map<int, int> f;
		for (int &x : a) {
			cin >> x;
			if (!x) ++ans;
			else ++f[x];
		}
		for (auto e : f) {
			if (e.second > e.first) ans += e.second - e.first;
			else if (e.second < e.first) ans += e.second;
		}
		cout << ans << '\n';
	}
}