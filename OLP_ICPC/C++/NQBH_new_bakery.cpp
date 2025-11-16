#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n, a, b;
		cin >> n >> a >> b;
		if (a >= b) cout << n * a << '\n';
		else {
			ll k = min(b - a, n);
			cout << k * b - (k - 1) * k / 2 + (n - k) * a << '\n';
		}
	}
}