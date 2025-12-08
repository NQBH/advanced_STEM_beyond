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
		cin >> n;
		vector<ll> a(n), b(n);
		for (ll &x : a) cin >> x;
		for (ll &x : b) cin >> x;
		ll curr_max = 0, curr_min = 0;
		for (int i = 0; i < n; ++i) {
			// R
			ll Rmax = curr_max - a[i], Rmin = curr_min - a[i];
			// B
			ll Bmin = b[i] - curr_min, Bmax = b[i] - curr_max;
			curr_max = max(Rmax, Bmin);
			curr_min = min(Rmin, Bmax);
		}
		cout << curr_max << '\n';
	}
}