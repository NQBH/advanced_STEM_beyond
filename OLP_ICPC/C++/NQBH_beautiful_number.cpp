#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll sum_digit(ll n) {
	ll ret = 0;
	if (n <= 9) return n;
	while (n > 0) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	ll q;
	cin >> q;
	vector<ll> S(153, 0); // 153 = 17 * 9
	for (ll i = 1; i <= 153; ++i) S[i] = sum_digit[i];
	while (q--) {
		ll ans = 0;
		ll l, r;
		cin >> l >> r;
		for (ll i = l; i <= r; ++i)
			if (i % 6 == 0) ++ans;
			else {
				ll tmp = sum_digit(i);
				if (!S[tmp]) S[tmp] = sum_digit(tmp);
				if (i >= 10 && (S[tmp] % 9 == 0 || S[tmp] % 9 == 3 || S[tmp] % 9 == 6)) ++ans;
			}
		cout << ans << '\n';
	}
}