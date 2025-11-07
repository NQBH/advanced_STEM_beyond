#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n, ans = 0;
		cin >> n;
		while (n) {
			ans += n;
			n >>= 1;
		}
		cout << ans << '\n';
	}
}