#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		ll ans = 1ll * m * (n - r) + 1ll * (n - r) * (m - 1) + m - c;
		cout << ans << '\n';
	}
}