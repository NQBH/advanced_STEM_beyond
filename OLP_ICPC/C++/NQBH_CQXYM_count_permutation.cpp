#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int m = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll ans = 1;
		ll N = 2 * n;
		for (ll i = 3; i <= N; ++i) {
			ans *= i;
			ans %= m;
		}
		cout << ans << '\n';
	}
}