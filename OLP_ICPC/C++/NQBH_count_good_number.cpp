#include <iostream>
using namespace std;
using ll = long long;

bool good(ll x) {
	return x % 2 && x % 3 && x % 5 && x % 7;
}

ll get_naive(ll x) {
	ll ans = 0;
	for (int i = 0; i < x; ++i)
		if (good(i)) ++ans;
	return ans;
}

ll get(ll r) {
	return (r / 210) * get_naive(210) + get_naive(r % 210);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		cout << get(r + 1) - get(l) << '\n';
	}
}