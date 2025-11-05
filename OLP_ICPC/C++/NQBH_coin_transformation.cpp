#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n < 4) cout << "1\n";
		else {
			ll ans = 1;
			while (n > 3) {
				ans <<= 1;
				n /= 4;
			}
			cout << ans << '\n';
		}
	}
}