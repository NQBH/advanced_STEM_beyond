#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, x, t;
		cin >> n >> x >> t;
		ll T = t / x;
		ll ans = T * (n - T) + T * (T - 1) / 2;
		cout << ans << '\n';
	}
}