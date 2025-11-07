#include <iostream>
using namespace std;
using ll = long long;
const int m = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n & 1) cout << "0\n";
		else { // ( (n / 2)!)^2
			ll ans = 1;
			for (int i = 2; i <= n / 2; ++i) {
				ans *= i;
				ans %= m;
			}
			ans *= ans;
			ans %= m;
			cout << ans << '\n';
		}
	}
}