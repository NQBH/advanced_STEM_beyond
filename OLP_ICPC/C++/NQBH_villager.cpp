#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		ll ans = 0;
		cin >> n;
		vector<int> g(n);
		for (int &x : g) cin >> x;
		sort(g.begin(), g.end());
		for (int i = n - 1; i >= 0; i -= 2) ans += g[i];
		cout << ans << '\n';
	}
}