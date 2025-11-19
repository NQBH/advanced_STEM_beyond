#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, s, t;
	cin >> n >> m;
	vector<ll> a(n + 1, 0), f(n + 1, 0), g(n + 1, 0); // f[i] = dmg received when fly from column 1 to column i, g[i] = dmg received when fly from column n back to column i
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 2; i <= n; ++i) {
		f[i] = f[i - 1];
		if (a[i] < a[i - 1]) f[i] += a[i - 1] - a[i];
	}
	for (int i = n - 1; i >= 1; --i) {
		g[i] = g[i + 1];
		if (a[i] < a[i + 1]) g[i] += a[i + 1] - a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> s >> t;
		if (s < t) cout << f[t] - f[s] << '\n';
		else cout << g[t] - g[s] << '\n';
	}
}