#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, k, x, y;
	cin >> n >> k;
	vector<vector<ll>> a(n + 1, vector<ll>(n + 1, -1));
	for (ll i = 0; i < k; ++i) {
		cin >> x >> y;
		a[x][y] = 0;
	}
	string d = "RDLU", s = ""; // direction
	ll idx = 0;
	for (ll i = 1; i < n; ++i) {
		for (ll j = 0; j < i; ++j)
			s = s + d[idx];
		if (idx == 3) idx = 0;
		else ++idx;
		for (ll j = 0; j < i; ++j)
			s += d[idx];
		if (idx == 3) idx = 0;
		else ++idx;
	}
	for (ll i = 1; i < n; ++i) s += 'R';
	// cout << s << '\n';
	x = (n + 1) / 2;
	y = (n + 1) / 2;
	if (a[x][y] == -1) a[x][y] = 1;
	ll val = a[x][y];
	for (ll i = 0; i < n * n; ++i) { // move to next cell
		if (s[i] == 'R') ++y;
		else if (s[i] == 'D') ++x;
		else if (s[i] == 'L') --y;
		else --x;
		if (a[x][y] == -1) {
			++val;
			a[x][y] = val;
		}
	}
	for (ll i = 1; i <= n; ++i) {
		for (ll j = 1; j <= n; ++j)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}